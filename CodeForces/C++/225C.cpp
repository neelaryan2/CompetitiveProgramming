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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> sums[2];
    sums[0].assign(m + 1, 0);
    sums[1].assign(m + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            int t = (c == '#');
            sums[t][j + 1]++;
        }
    }
    for (int i = 1; i <= m; i++)
        for (int c : {0, 1})
            sums[c][i] += sums[c][i - 1];
    vector<int> dp[2];
    dp[0].assign(m + 1, 1e6 + 10);
    dp[1].assign(m + 1, 1e6 + 10);
    dp[0][0] = dp[1][0] = 0;
    trace(sums[0]);
    trace(sums[1]);
    for (int i = 0; i <= m; i++) {
        for (int j = x; j <= y; j++) {
            if (i + j > m) break;
            for (int c : {0, 1}) {
                dp[c][i + j] = min(dp[c][i + j], dp[c ^ 1][i] + sums[c][i + j] - sums[c][i]);
            }
        }
    }
    trace(dp[0]);
    trace(dp[1]);
    int ans = min(dp[0][m], dp[1][m]);
    cout << ans << '\n';
}
