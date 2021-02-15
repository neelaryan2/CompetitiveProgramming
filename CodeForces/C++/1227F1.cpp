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
#define rall(v) (v).rbegin(), (v).rend()

const int inf = 1e9 + 7;
const int kMod = 998244353;
// const int kMod = 1e9 + 7;
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
    // if (b.get() == 0) return 0;
    ModInt r;
    e = e % (kMod - 1);
    if (e < 0) e += kMod - 1;
    for (r = 1; e; e >>= 1, b = b * b)
        if (e & 1) r = r * b;
    return r;
}
vector<ModInt> fact, invfact;
void factorials(int n) {
    fact.resize(n + 1, 1);
    invfact.resize(n + 1, 1);
    for (int i = 1; i <= n; ++i)
        fact[i] = fact[i - 1] * i;
    invfact[n] = lgpow(fact[n]);
    for (int i = n - 1; i >= 1; --i)
        invfact[i] = invfact[i + 1] * (i + 1);
}
ModInt choose(int n, int k) {
    if (n < 0 || k < 0 || k > n) return 0;
    return fact[n] * invfact[k] * invfact[n - k];
}
void solve(int test) {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int& e : h) cin >> e;
    if (k == 1) {
        cout << 0;
        return;
    }
    h.eb(h[0]);
    ModInt factor = 1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (h[i] == h[i + 1])
            factor = factor * k;
        else
            cnt++;
    }
    ModInt ans = 0;
    for (int i = 1; i <= cnt; i++) {
        for (int j = 0; j < min(i, cnt - i + 1); j++) {
            ans = ans + choose(cnt, i) * choose(cnt - i, j) * lgpow(k - 2, cnt - i - j);
        }
    }
    ans = ans * factor;
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    factorials(3000);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << '\n';
    }
}