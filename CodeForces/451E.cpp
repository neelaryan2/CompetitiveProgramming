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
const int kMod = 1e9 + 7;
struct ModInt {
    long long n;
    ModInt(long long n = 0) : n(n % kMod) {}
    long long get() { return n = (n < 0 ? n + kMod : n); }
    ModInt operator+(const ModInt& oth) { return n + oth.n; }
    ModInt operator-(const ModInt& oth) { return n - oth.n; }
    ModInt operator*(const ModInt& oth) { return n * oth.n; }
    ModInt operator==(const ModInt& oth) { return get() == ModInt(oth).get(); }
    friend std::ostream& operator<<(std::ostream& os, const ModInt& a) { return os << ModInt(a).get(); }
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
ModInt choose(ll n, int k) {
    ModInt up = 1, down = 1;
    for (int i = 0; i < k; i++) {
        up = up * (n - i);
        down = down * (i + 1);
    }
    return up * lgpow(down);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    ll s;
    cin >> s;
    vector<ll> f(n);
    for (ll& e : f) cin >> e;
    ModInt ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        int c = __builtin_popcount(i);
        c = (c & 1) ? -1 : 1;
        ll curs = s;
        for (int j = 0; j < n; j++)
            if ((i >> j) & 1)
                curs -= f[j] + 1;
        if (curs < 0) continue;
        ans = ans + choose(curs + n - 1, n - 1) * c;
    }
    cout << ans << '\n';
}