#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
int dp[51][51][51][51];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    n++;
    char g[n][n];
    int p[n][n];
    n--;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            p[i][j] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[i][j] == '#') p[i][j]++;
            p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = n; k >= 0; k--) {
                for (int l = n; l >= 0; l--) {
                    if (i >= k && j >= l)
                        dp[i][j][k][l] = max(i - k, j - l) + 1;
                    else
                        dp[i][j][k][l] = 0;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = i; k >= 1; k--) {
                for (int l = j; l >= 1; l--) {
                    for (int r = i; r >= k; r--) {
                        int tot = p[i][j] - p[i][l - 1] - p[r - 1][j] + p[r - 1][l - 1];
                        if (tot == 0) {
                            dp[i][j][k][l] = min(dp[i][j][k][l], dp[r - 1][j][k][l]);
                        } else {
                            dp[i][j][k][l] = min(dp[i][j][k][l], dp[r - 1][j][k][l] + dp[i][j][r][l]);
                        }
                    }
                    for (int c = j; c >= l; c--) {
                        int tot = p[i][j] - p[i][c - 1] - p[k - 1][j] + p[k - 1][c - 1];
                        if (tot == 0) {
                            dp[i][j][k][l] = min(dp[i][j][k][l], dp[i][c - 1][k][l]);
                        } else {
                            dp[i][j][k][l] = min(dp[i][j][k][l], dp[i][c - 1][k][l] + dp[i][j][k][c]);
                        }
                    }
                }
            }
        }
    }
    cerr << dp[5][5][3][3] << endl;
    int ans = dp[n][n][1][1];
    cout << ans << '\n';
}
