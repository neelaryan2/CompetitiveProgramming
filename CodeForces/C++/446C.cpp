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
// const int kMod = 998244353;
const int kMod = 1e9 + 9;
struct ModInt {
    long long n;
    ModInt(long long n = 0) : n(n % kMod) {}
    ModInt operator+(const ModInt& oth) { return n + oth.n; }
    ModInt operator-(const ModInt& oth) { return n - oth.n; }
    ModInt operator*(const ModInt& oth) { return n * oth.n; }
    long long get() { return n < 0 ? n + kMod : n; }
    friend ostream& operator<<(ostream& os, ModInt const& a) { return os << ModInt(a.n).get(); }
};
ModInt lgpow(ModInt b, int e = -1) {
    if (b.get() == 0) return 0;
    ModInt r;
    e = e % (kMod - 1);
    if (e < 0) e += kMod - 1;
    for (r = 1; e; e >>= 1, b = b * b)
        if (e & 1) r = r * b;
    return r;
}
template <int B>
struct seg_tree_lazy {
    vector<ModInt> t, prod, pows;
    vector<bool> dont;
    int n;
    ModInt inv;
    void init(int m) {
        n = m;
        inv = lgpow(B - 1);
        t.assign(4 * n, 0);
        prod.assign(4 * n, 0);
        dont.assign(4 * n, true);
        pows.assign(n + 10, 1);
        for (int i = 1; i < n + 10; i++)
            pows[i] = pows[i - 1] * B;
    }
    void apply(int v, ModInt value, int c) {
        prod[v] = prod[v] + value;
        t[v] = t[v] + (pows[c] - 1) * inv * value;
        dont[v] = false;
    }
    void push(int v, int l, int r) {
        if (dont[v]) return;
        int L = v * 2, R = L + 1;
        apply(v * 2, prod[v], l);
        apply(v * 2 + 1, prod[v] * pows[l], r);
        prod[v] = 0, dont[v] = true;
    }
    int add(int v, int tl, int tr, int l, int r, ModInt x) {
        if (l > r) return 0;
        if (l == tl && tr == r) {
            int len = tr - tl + 1;
            apply(v, x, len);
            return len;
        } else {
            int tm = (tl + tr) / 2;
            push(v, tm - tl + 1, tr - tm);
            int done = add(v * 2, tl, tm, l, min(r, tm), x);
            x = x * pows[done];
            done += add(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
            t[v] = t[v * 2] + t[v * 2 + 1];
            return done;
        }
    }
    ModInt query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl && tr == r) return t[v];
        int tm = (tl + tr) / 2;
        push(v, tm - tl + 1, tr - tm);
        return query(v * 2, tl, tm, l, min(r, tm)) +
               query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
    void add(int l, int r, ModInt x) {
        int seg = add(1, 0, n - 1, l, r, x);
        assert(seg == r - l + 1);
    }
    ModInt query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};
const int A = 276601605;
const int B1 = 691504013;
const int B2 = 308495997;
seg_tree_lazy<B1> st1;
seg_tree_lazy<B2> st2;
void solve(int test) {
    int n, m;
    cin >> n >> m;
    st1.init(n);
    st2.init(n);
    vector<ModInt> a(n + 1, 0);
    for (int i = 1, e; i <= n; i++) {
        cin >> e;
        a[i] = a[i - 1] + e;
    }
    while (m--) {
        int t, l, r;
        cin >> t >> l >> r;
        l--, r--;
        if (t == 1) {
            st1.add(l, r, B1);
            st2.add(l, r, B2);
        }
        if (t == 2) {
            ModInt a1 = st1.query(l, r);
            ModInt a2 = st2.query(l, r);
            ModInt ans = (a1 - a2) * A;
            ans = ans + a[r + 1] - a[l];
            cout << ans << '\n';
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << "\n";
    }
}
