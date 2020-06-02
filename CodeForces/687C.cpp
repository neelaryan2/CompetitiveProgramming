/* Author - Neel Aryan (@neelaryan2) */
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
    int n, x;
    cin >> n >> x;
    int c[n + 1];
    bool dp[n + 1][x + 1][x + 1];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= x; j++)
            for (int k = 0; k <= x; k++)
                dp[i][j][k] = false;
    dp[0][0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            for (int k = 0; k <= x; k++) {
                if (dp[i - 1][j][k]) {
                    dp[i][j][k] = true;
                    if (j + c[i] <= x) {
                        dp[i][j + c[i]][k] = true;
                        if (k + c[i] <= x)
                            dp[i][j + c[i]][k + c[i]] = true;
                    }
                }
            }
        }
    }
    vector<int> ans;
    for (int k = 0; k <= x; k++) {
        if (dp[n][x][k])
            ans.pb(k);
    }
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
    cout << '\n';
}
