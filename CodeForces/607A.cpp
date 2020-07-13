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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pii> vec(n);
    for (pii& p : vec)
        cin >> p.fi >> p.se;
    sort(all(vec));
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
        int d = vec[i].fi - vec[i].se;
        int j = lb(all(vec), mp(d, -1)) - vec.begin() - 1;
        trace(vec[i], vec[j]);
        dp[i] = (j < 0) ? i : dp[j] + i - j - 1;
    }
    trace(dp);
    int ans = dp[n - 1];
    for (int i = n - 1; i >= 0; i--)
        ans = min(ans, dp[i] + n - i - 1);
    cout << ans << '\n';
}
