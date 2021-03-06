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
ll f(ll n) { return (n * (n - 1)) / 2; }
void solve(int test) {
    ll m, d, w;
    cin >> m >> d >> w;
    ll k = min(m, d);
    w /= __gcd(w, d - 1);
    ll q = k / w, r = k % w;
    ll ans = w * f(q) + r * q;
    cout << ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << "\n";
    }
}
