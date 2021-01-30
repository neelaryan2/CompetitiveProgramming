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

void solve(int test) {
    int n, m, k;
    cin >> n >> m >> k;
    int ch = m / 2;
    int dp[m + 1][ch + 1][k];

    vector<int> ans(k, -inf);
    vector<int> newdp, a(m);
    ans[0] = 0;

    for (int it = 0; it < n; it++) {
        for (int& e : a)
            cin >> e;
        memset(dp, -inf, sizeof dp);
        dp[0][0][0] = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j <= min(ch, i); j++) {
                for (int r = 0; r < k; r++) {
                    int nr = (r + a[i - 1]) % k;
                    dp[i][j][r] = max(dp[i][j][r], dp[i - 1][j][r]);
                    if (j > 0)
                        dp[i][j][nr] = max(dp[i][j][nr], dp[i - 1][j - 1][r] + a[i - 1]);
                }
            }
        }
        newdp.assign(k, -inf);
        for (int r1 = 0; r1 < k; r1++) {
            int mx = -inf;
            for (int j = 0; j <= ch; j++)
                mx = max(mx, dp[m][j][r1]);
            for (int r2 = 0; r2 < k; r2++) {
                int nr = (r1 + r2) % k;
                newdp[nr] = max(newdp[nr], mx + ans[r2]);
            }
        }
        swap(newdp, ans);
    }
    cout << ans[0];
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
        cout << '\n';
    }
}
