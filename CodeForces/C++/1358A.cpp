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

void solve() {
    ll n, m;
    cin >> n >> m;
    if ((n * m) % 2 == 0) {
        ll ans = (n * m) / 2;
        cout << ans << '\n';
        return;
    }
    ll ans1 = (n / 2) * m + m / 2 + 1;
    ll ans2 = (m / 2) * n + n / 2 + 1;
    ll ans = min(ans1, ans2);
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
