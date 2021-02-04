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
void solve(int test) {
    int n, m;
    cin >> n >> m;
    int a[n + 2][m + 2], dp[4][n + 2][m + 2];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[0][i][j] = a[i][j] + max(dp[0][i - 1][j], dp[0][i][j - 1]);
    for (int i = n; i >= 1; i--)
        for (int j = 1; j <= m; j++)
            dp[1][i][j] = a[i][j] + max(dp[1][i + 1][j], dp[1][i][j - 1]);
    for (int i = n; i >= 1; i--)
        for (int j = m; j >= 1; j--)
            dp[2][i][j] = a[i][j] + max(dp[2][i + 1][j], dp[2][i][j + 1]);
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 1; j--)
            dp[3][i][j] = a[i][j] + max(dp[3][i - 1][j], dp[3][i][j + 1]);
    int ans = 0;
    for (int i = n - 1; i >= 2; i--) {
        for (int j = m - 1; j >= 2; j--) {
            ans = max(ans, dp[0][i - 1][j] + dp[2][i + 1][j] + dp[1][i][j - 1] + dp[3][i][j + 1]);
            ans = max(ans, dp[3][i - 1][j] + dp[1][i + 1][j] + dp[0][i][j - 1] + dp[2][i][j + 1]);
        }
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
