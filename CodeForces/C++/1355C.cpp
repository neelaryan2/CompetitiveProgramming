/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
ll nc2(ll n) {
    if (n <= 1) return 0;
    return (n * (n - 1)) / 2;
}
void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = 0;
    for (ll z = 0; z <= d - c; z++) {
        ll up = z + c - b - a;
        ans += (b - a + 1) * (c - b + 1);
        trace(ans);
        ans -= nc2(up + 2);
        ans += nc2(up - b + a + 1);
        ans += nc2(up - c + b + 1);
        ans -= nc2(up + a - c);
        trace(up, ans);
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
