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
struct num {
    ld x, y;
    num(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}
    num operator+(const num& b) { return num(x + b.x, y + b.y); }
    num operator-(const num& b) { return num(x - b.x, y - b.y); }
    num operator*(const num& b) { return num(x * b.x - y * b.y, x * b.y + y * b.x); }
    num conj() { return num(x, -y); }
    num pow(ll b = -1) {
        if (x == 0 && y == 0) return num(0, 0);
        if (b < 0) {
            ld n = (x * x + y * y);
            return num(x / n, -y / n).pow(-b);
        }
        num r = num(1, 0), a = *this;
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
            ld a = acos(-1) / k;
            num z = num(cos(a), sin(a));
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
    static vector<ld> multiply(const vector<ld>& a, const vector<ld>& b) {
        int sza = a.size();
        int szb = b.size();
        int s = sza + szb - 1;
        if (s <= 0) return vector<ld>();
        int L = s > 1 ? 32 - __builtin_clz(s - 1) : 0, n = 1 << L;
        vector<num> fa(n), fb(n);
        fill(fa.begin(), fa.begin() + n, num(0, 0));
        for (int i = 0; i < sza; i++)
            fa[i].x = a[i];
        for (int i = 0; i < szb; i++)
            fa[i].y = b[i];
        fft(fa, n);
        for (num& x : fa) x = x * x;
        for (int i = 0; i < n; i++)
            fb[i] = fa[(n - i) & (n - 1)] - fa[i].conj();
        fft(fb, n);
        vector<ld> r(s);
        for (int i = 0; i < s; i++)
            r[i] = fb[i].y / (4 * n);
        return r;
    }
    // Integer multiply mod m (num = complex) /// start-hash
    static vector<int> multiply_mod(const vector<int>& a, const vector<int>& b, int m) {
        int sza = a.size();
        int szb = b.size();
        int s = sza + szb - 1;
        if (s <= 0) return vector<int>();
        int L = s > 1 ? 32 - __builtin_clz(s - 1) : 0, n = 1 << L;
        vector<num> fa(n), fb(n);
        for (int i = 0; i < sza; i++)
            fa[i] = num(a[i] & ((1 << 15) - 1), a[i] >> 15);
        fill(fa.begin() + sza, fa.begin() + n, num(0, 0));
        for (int i = 0; i < szb; i++)
            fb[i] = num(b[i] & ((1 << 15) - 1), b[i] >> 15);
        fill(fb.begin() + szb, fb.begin() + n, num(0, 0));
        fft(fa, n), fft(fb, n);
        ld r0 = 0.5 / n;
        for (int i = 0; i <= n / 2; i++) {
            int j = (n - i) & (n - 1);
            num g0 = (fb[i] + fb[j].conj()) * r0;
            num g1 = (fb[i] - fb[j].conj()) * r0;
            swap(g1.x, g1.y);
            g1.y *= -1;
            if (j != i) {
                swap(fa[j], fa[i]);
                fb[j] = fa[j] * g1;
                fa[j] = fa[j] * g0;
            }
            fb[i] = fa[i] * g1.conj();
            fa[i] = fa[i] * g0.conj();
        }
        fft(fa, n), fft(fb, n);
        vector<int> r(s, 0);
        for (int i = 0; i < s; i++)
            r[i] = int((ll(fa[i].x + 0.5) + (ll(fa[i].y + 0.5) % m << 15) + (ll(fb[i].x + 0.5) % m << 15) + (ll(fb[i].y + 0.5) % m << 30)) % m);
        return r;
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
        for (int i = 1; i <= sza; i++)
            b.coef[i] = coef[i - 1] * num(i).pow();
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
        while (p < sza && coef[p].x == 0 && coef[p].y == 0) ++p;
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
const int mod = 1009;
vector<int> cnt;
vector<int> sex(int l, int r) {
    if (l == r) {
        vector<int> a(cnt[l] + 1, 1);
        return a;
    }
    int m = (l + r) / 2;
    vector<int> lef = sex(l, m);
    vector<int> righ = sex(m + 1, r);
    return poly::multiply_mod(lef, righ, mod);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    cnt.assign(m, 0);
    for (int i = 0, e; i < n; i++) {
        cin >> e, e--;
        cnt[e]++;
    }
    vector<int> f = sex(0, m - 1);
    cout << f[k] << '\n';
}