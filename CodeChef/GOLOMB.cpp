#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using ld = long double;
using pii = pair<ll, ll>;
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
const int kMod = 1e9 + 7;
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
vector<int> vals;
vector<ll> L, R;
vector<ModInt> sums;
ll pre(int n) {
    ll sum = 0;
    vals.resize(n + 1, 0);
    sums.resize(n + 1, 0);
    L.resize(n + 1, 0);
    R.resize(n + 1, 0);
    for (int i = 0; i < n; i++) {
        vals[i + 1] = 1 + vals[i + 1 - vals[vals[i]]];
        L[i + 1] = sum + 1;
        R[i + 1] = sum + vals[i + 1];
        sums[i + 1] = sums[i] + ModInt(i + 1) * (i + 1) * vals[i + 1];
        sum += vals[i + 1];
    }
    return sum;
}
void solve(int test) {
    ll l, r;
    cin >> l >> r;
    ll lef = lb(all(L), l) - L.begin();
    if (L[lef] != l) lef--;
    ll righ = lb(all(R), r) - R.begin();
    ModInt ans = ModInt(lef) * lef * (L[lef] - l) + ModInt(r - R[righ]) * righ * righ;
    trace(ans);
    ans = ans + sums[righ] - sums[lef - 1];
    cout << ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll sum = pre(1e7);
    int t = 1;
    cin >> t;
    // trace(L);
    // trace(R);
    // trace(sums);
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << "\n";
    }
}
