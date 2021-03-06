#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

const int mod = 163577857, g = 5;
// For p < 2^30 there is also (5 << 25, 3), (7 << 26, 3),
// (479 << 21, 3) and (483 << 21, 5). Last two are > 10^9.
struct num {
    int v;
    num(ll v_ = 0) : v(int(v_ % mod)) {
        if (v < 0) v += mod;
    }
    explicit operator int() const { return v; }
    num operator+(const num& b) { return num(v + b.v); }
    num operator-(const num& b) { return num(v + mod - b.v); }
    num operator*(const num& b) { return num(1LL * v * b.v); }
    num pow(long long b_ = -1) {
        if (v == 0) return 0;
        int b = b_ % (mod - 1);
        if (b < 0) b += mod - 1;
        num r = 1, a = *this;
        do {
            if (b & 1) r = r * a;
            a = a * a;
        } while (b >>= 1);
        return r;
    }
};
vector<int> rev({0, 1});
vector<num> rt(2, num(1));
struct poly {
    static void init(int n) {
        int rts = rt.size();
        if (n <= rts) return;
        rev.resize(n);
        for (int i = 0; i < n; i++)
            rev[i] = (rev[i >> 1] | ((i & 1) * n)) >> 1;
        rt.reserve(n);
        for (int k = rts; k < n; k *= 2) {
            rt.resize(2 * k);
            num z = num(g).pow((mod - 1) / (2 * k));
            for (int i = k / 2; i < k; i++)
                rt[2 * i] = rt[i], rt[2 * i + 1] = rt[i] * z;
        }
    }
    static void fft(vector<num>& a, int n) {
        init(n);
        int s = rev.size();
        s = __builtin_ctz(s / n);
        for (int i = 0; i < n; i++)
            if (i < (rev[i] >> s))
                swap(a[i], a[rev[i] >> s]);
        for (int k = 1; k < n; k *= 2) {
            for (int i = 0; i < n; i += 2 * k) {
                for (int j = 0; j < k; j++) {
                    num t = rt[j + k] * a[i + j + k];
                    a[i + j + k] = a[i + j] - t;
                    a[i + j] = a[i + j] + t;
                }
            }
        }
    }
    static vector<num> inverse(vector<num>& a) {
        if (a.empty()) return {};
        vector<num> b(1);
        b[0] = a[0].pow();
        b.reserve(2 * a.size());
        vector<num> fa;
        while (b.size() < a.size()) {
            int n = 2 * b.size();
            b.resize(2 * n, 0);
            if (fa.size() < 2 * n) fa.resize(2 * n);
            fill(fa.begin(), fa.begin() + 2 * n, 0);
            copy(a.begin(), a.begin() + min(n, (int)a.size()), fa.begin());
            fft(b, 2 * n), fft(fa, 2 * n);
            num d = num(2 * n).pow();
            for (int i = 0; i < 2 * n; i++)
                b[i] = b[i] * (num(2) - fa[i] * b[i]) * d;
            reverse(b.begin() + 1, b.end());
            fft(b, 2 * n);
            b.resize(n);
        }
        b.resize(a.size());
        return b;
    }
    static vector<num> multiply(vector<num> a, vector<num> b) {
        int sza = a.size();
        int szb = b.size();
        int s = sza + szb - 1;
        if (s <= 0) return {};
        int L = s > 1 ? 32 - __builtin_clz(s - 1) : 0, n = 1 << L;
        a.resize(n), b.resize(n);
        fft(a, n), fft(b, n);
        num d = num(n).pow();
        for (int i = 0; i < n; i++)
            a[i] = a[i] * b[i] * d;
        reverse(a.begin() + 1, a.end());
        fft(a, n);
        a.resize(s);
        return a;
    }
    vector<num> coef;
    poly(vector<num> v = {}) { coef = v; }
    poly& operator+=(const poly& b) {
        int sza = coef.size();
        int szb = b.coef.size();
        if (sza < szb) coef.resize(szb);
        for (int i = 0; i < szb; i++)
            coef[i] = coef[i] + b.coef[i];
        return *this;
    }
    poly operator+(const poly& b) {
        poly r = *this;
        r += b;
        return r;
    }
    poly& operator-=(const poly& b) {
        int sza = coef.size();
        int szb = b.coef.size();
        if (sza < szb) coef.resize(szb);
        for (int i = 0; i < szb; i++)
            coef[i] = coef[i] - b.coef[i];
        return *this;
    }
    poly operator-(const poly& b) {
        poly r = *this;
        r -= b;
        return r;
    }
    poly operator*(const poly& b) {
        return poly(multiply(coef, b.coef));
    }
    poly& operator*=(const poly& b) {
        coef = multiply(coef, b.coef);
        return *this;
    }
    poly& operator*=(const num& b) {
        for (num& x : coef) x = x * b;
        return *this;
    }
    // Polynomial floor division; no leading 0's plz
    poly& operator/=(poly b) {
        int sza = coef.size();
        int szb = b.coef.size();
        if (sza < szb) {
            coef.clear();
            return *this;
        }
        int s = sza - szb + 1;
        reverse(coef.begin(), coef.end());
        reverse(b.coef.begin(), b.coef.end());
        coef.resize(s), b.coef.resize(s);
        coef = multiply(coef, inverse(b.coef));
        coef.resize(s);
        reverse(coef.begin(), coef.end());
        return *this;
    }
    poly operator/(const poly& b) {
        poly r = *this;
        r /= b;
        return r;
    }
    poly& operator%=(const poly& b) {
        int sza = coef.size();
        int szb = b.coef.size();
        if (sza >= szb) {
            poly c = *this;
            c /= b;
            c *= b;
            coef.resize(szb - 1);
            for (int i = 0; i < sza; i++)
                coef[i] = coef[i] - c.coef[i];
        }
        return *this;
    }
    poly operator%(const poly& b) {
        poly r = *this;
        r %= b;
        return r;
    }
    poly deriv() {
        if (coef.empty()) return poly();
        int sza = coef.size();
        poly b;
        b.coef.resize(sza - 1);
        for (int i = 1; i < sza; i++)
            b.coef[i - 1] = coef[i] * i;
        return b;
    }
    poly integ() {
        int sza = coef.size();
        poly b;
        b.coef.resize(sza + 1);
        b.coef[1] = 1;
        for (int i = 2; i <= sza; i++)
            b.coef[i] = b.coef[mod % i] * (-mod / i);
        for (int i = 1; i <= sza; i++)
            b.coef[i] = coef[i - 1] * b.coef[i];
        return b;
    }
    poly log() {  // coef[0] == 1
        poly a = this->deriv();
        poly b = poly(multiply(coef, inverse(a.coef)));
        b = b.integ();
        b.coef.resize(coef.size());
        return b;
    }
    poly exp() {  // coef[0] == 0
        poly b;
        b.coef.assign(1, num(1));
        if (coef.empty()) return b;
        while (b.coef.size() < coef.size()) {
            int sza = coef.size();
            int szb = b.coef.size();
            int n = min(szb * 2, sza);
            b.coef.resize(n);
            poly v;
            v.coef.resize(n);
            for (int i = 0; i < n; i++)
                v.coef[i] = coef[i];
            v -= b.log();
            v.coef[0] = v.coef[0] + num(1);
            b *= v;
            b.coef.resize(n);
        }
        return b;
    }
    poly pow(int m) {  // m >= 0
        poly b;
        int sza = coef.size();
        b.coef.resize(sza);
        if (m == 0) {
            b.coef[0] = 1;
            return b;
        }
        int p = 0;
        while (p < sza && coef[p].v == 0) ++p;
        if (1LL * m * p >= sza) return b;
        num mu = coef[p].pow(m), di = coef[p].pow();
        poly c;
        c.coef.resize(sza - m * p);
        for (int i = 0; i < c.coef.size(); i++)
            c.coef[i] = coef[i + p] * di;
        c = c.log();
        for (num& v : c.coef)
            v = v * m;
        c = c.exp();
        for (int i = 0; i < c.coef.size(); i++)
            b.coef[i + m * p] = c.coef[i] * mu;
        return b;
    }
    vector<num> eval(const vector<num>& x) {
        int n = x.size();
        if (!n) return {};
        vector<poly> up(2 * n);
        for (int i = 0; i < n; i++) {
            vector<num> tmp = {num(num(0) - x[i]), num(1)};
            up[i + n] = poly(tmp);
        }
        for (int i = n - 1; i >= 1; i--)
            up[i] = up[2 * i] * up[2 * i + 1];
        vector<poly> down(2 * n);
        down[1] = (*this) % up[1];
        for (int i = 2; i < 2 * n; i++)
            down[i] = down[i / 2] % up[i];
        vector<num> y(n);
        for (int i = 0; i < n; i++)
            y[i] = down[i + n].coef[0];
        return y;
    }
};
poly interp(const vector<num>& x, const vector<num>& y) {
    int n = x.size();
    assert(n);
    vector<poly> up(n * 2);
    for (int i = 0; i < n; i++) {
        vector<num> tmp = {num(num(0) - x[i]), num(1)};
        up[i + n] = poly(tmp);
    }
    for (int i = n - 1; i >= 1; i--)
        up[i] = up[2 * i] * up[2 * i + 1];
    vector<num> a = up[1].deriv().eval(x);
    vector<poly> down(2 * n);
    for (int i = 0; i < n; i++) {
        vector<num> tmp = {a[i].pow() * y[i]};
        down[i + n] = poly(tmp);
    }
    for (int i = n - 1; i >= 1; i--)
        down[i] = down[i * 2] * up[i * 2 + 1] + down[i * 2 + 1] * up[i * 2];
    return down[1];
}
vector<num> fact, invfact;
void factorials(int n) {
    fact.resize(n + 1, 1);
    invfact.resize(n + 1, 1);
    for (int i = 1; i <= n; ++i)
        fact[i] = fact[i - 1] * i;
    invfact[n] = fact[n].pow();
    for (int i = n - 1; i >= 1; --i)
        invfact[i] = invfact[i + 1] * (i + 1);
}
num choose(int n, int k) {
    return fact[n] * invfact[k] * invfact[n - k];
}
void solve() {
    int n, plus = 0, minus = 0, zero = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        if (e == -1) minus++;
        if (e == 1) plus++;
        if (e == 0) zero++;
    }
    factorials(max(plus, minus) + 5);
    vector<num> pos(n + 1, 0), neg(n + 1, 0);
    for (int i = 0; i <= plus; i++)
        pos[i] = choose(plus, i);
    for (int i = 0; i <= minus; i++)
        neg[i] = choose(minus, i);
    reverse(all(neg));
    poly ans = poly(pos) * poly(neg);
    num pw = num(2).pow(zero);
    for (int i = 0; i <= 2 * n; i++)
        ans.coef[i] = ans.coef[i] * pw;
    ans.coef[n] = ans.coef[n] - 1;
    for (int i = 0; i <= 2 * n; i++)
        cout << int(ans.coef[i]) << ' ';
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}