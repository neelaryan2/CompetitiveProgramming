namespace fft {
const int mod = 998244353, g = 3;
// For p < 2^30 there is also (5 << 25, 3), (7 << 26, 3),
// (479 << 21, 3) and (483 << 21, 5). Last two are > 10^9.
struct num {  /// start-hash
    int v;
    num(ll v_ = 0) : v(int(v_ % mod)) {
        if (v < 0) v += mod;
    }
    explicit operator int() const { return v; }
};
inline num operator+(num a, num b) { return num(a.v + b.v); }
inline num operator-(num a, num b) { return num(a.v + mod - b.v); }
inline num operator*(num a, num b) { return num(1LL * a.v * b.v); }
inline num pow(num a, int b) {
    num r = 1;
    do {
        if (b & 1) r = r * a;
        a = a * a;
    } while (b >>= 1);
    return r;
}
inline num inv(num a) { return pow(a, mod - 2); }

using vn = vector<num>;
vi rev({0, 1});
vn rt(2, num(1)), fa, fb;

inline void init(int n) {  /// start-hash
    if (n <= sz(rt)) return;
    rev.resize(n);
    rep(i, 0, n) rev[i] = (rev[i >> 1] | ((i & 1) * n)) >> 1;
    rt.reserve(n);
    for (int k = sz(rt); k < n; k *= 2) {
        rt.resize(2 * k);
        num z = pow(num(g), (mod - 1) / (2 * k));  // NTT
        rep(i, k / 2, k) rt[2 * i] = rt[i], rt[2 * i + 1] = rt[i] * z;
    }
}  /// end-hash

inline void fft(vector<num>& a, int n) {  /// start-hash
    init(n);
    int s = __builtin_ctz(sz(rev) / n);
    rep(i, 0, n) if (i<rev[i]> > s) swap(a[i], a[rev[i] >> s]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k) rep(j, 0, k) {
                num t = rt[j + k] * a[i + j + k];
                a[i + j + k] = a[i + j] - t;
                a[i + j] = a[i + j] + t;
            }
}  /// end-hash

// Complex/NTT
vn multiply(vn a, vn b) {  /// start-hash
    int s = sz(a) + sz(b) - 1;
    if (s <= 0) return {};
    int L = s > 1 ? 32 - __builtin_clz(s - 1) : 0, n = 1 << L;
    a.resize(n), b.resize(n);
    fft(a, n), fft(b, n);
    num d = inv(num(n));
    rep(i, 0, n) a[i] = a[i] * b[i] * d;
    reverse(a.begin() + 1, a.end());
    fft(a, n);
    a.resize(s);
    return a;
}  /// end-hash

// Complex/NTT power-series inverse
// Doubles b as b[:n] = (2 - a[:n] * b[:n/2]) * b[:n/2]
vn inverse(const vn& a) {  /// start-hash
    if (a.empty()) return {};
    vn b({inv(a[0])});
    b.reserve(2 * a.size());
    while (sz(b) < sz(a)) {
        int n = 2 * sz(b);
        b.resize(2 * n, 0);
        if (sz(fa) < 2 * n) fa.resize(2 * n);
        fill(fa.begin(), fa.begin() + 2 * n, 0);
        copy(a.begin(), a.begin() + min(n, sz(a)), fa.begin());
        fft(b, 2 * n);
        fft(fa, 2 * n);
        num d = inv(num(2 * n));
        rep(i, 0, 2 * n) b[i] = b[i] * (2 - fa[i] * b[i]) * d;
        reverse(b.begin() + 1, b.end());
        fft(b, 2 * n);
        b.resize(n);
    }
    b.resize(a.size());
    return b;
} 
}

// For multiply_mod, use num = modnum, poly = vector<num>
using fft::num;
using poly = fft::vn;
using fft::inverse;
using fft::multiply;

struct poly {
    vector<num> coef;
    poly(const vector<num>& v) { coef = v; }
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
    poly operator+(const poly& b) {
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
    poly operator/=(poly b) {
        int sza = coef.size();
        int szb = b.coef.size();
        if (sza < szb) return {
                coef.clear();
                return *this;
            }
        int s = sza - szb + 1;
        reverse(coef.begin(), coef.end());
        reverse(b.coef.begin(), b.coef.end());
        coef.resize(s), b.coef.resize(s);
        coef = multiply(coef, inverse(move(b.coef)));
        coef.resize(s);
        reverse(coef.begin(), coef.end());
        return *this;
    }
    poly& operator/(const poly& b) {
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
        if (coef.empty()) return poly({});
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
            b[i] = b[fft::mod % i] * (-fft::mod / i);
        for (int i = 1; i <= sza; i++)
            b[i] = a[i - 1] * b[i];
        return b;
    }
    poly log() {  // coef[0] == 1
        poly a = this->deriv();
        poly b = poly(multiply(a.coef, inverse(a.coef)));
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
            v.coef[0] = c.coef[0] + num(1);
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
        num mu = pow(coef[p], m), di = inv(coef[p]);
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
        for (int i = 0; i < n; i++)
            up[i + n] = poly({num(0 - x[i]), num(1)});
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
    int n = sz(x);
    assert(n);
    vector<poly> up(n * 2);
    for (int i = 0; i < n; i++) u
		p[i + n] = poly({num(0 - x[i]), num(1)});
    for (int i = n - 1; i >= 1; i--) 
		up[i] = up[2 * i] * up[2 * i + 1];
    vector<num> a = up[1].deriv().eval(x);
    vector<poly> down(2 * n);
    for (int i = 0; i < n; i++)
		down[i + n] = poly({y[i] * inv(a.coef[i])});
    for (int i = n - 1; i >= 1; i--) 
		down[i] = down[i * 2] * up[i * 2 + 1] + down[i * 2 + 1] * up[i * 2];
    return down[1];
}  