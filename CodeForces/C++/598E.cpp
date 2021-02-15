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

const int inf = 1e8 + 7;
int dp[31][31][51];
int solver(int n, int m, int k) {
    if (n * m < k) return inf;
    if (k == 0 || n * m == k) return 0;
    if (dp[n][m][k] != -1) return dp[n][m][k];
    int ans = inf;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            int cur = solver(n - i, m, k - j) + solver(i, m, j) + m * m;
            ans = min(cur, ans);
        }
    }
    for (int i = 1; i < m; i++) {
        for (int j = 0; j <= k; j++) {
            int cur = solver(n, m - i, k - j) + solver(n, i, j) + n * n;
            ans = min(cur, ans);
        }
    }
    return dp[n][m][k] = ans;
}
void solve(int test) {
    int n, m, k;
    cin >> n >> m >> k;
    int ans = solver(n, m, k);
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof dp);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << '\n';
    }
}
