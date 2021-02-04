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
    int n, m, b, mod;
    cin >> n >> m >> b >> mod;
    vector<int> a(n);
    for (int& e : a) cin >> e;

    int dp[2][m + 1][b + 1];
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;

    int t = 1;
    for (int k = 1; k <= n; k++) {
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= b; j++) {
                int c = a[k - 1];
                dp[t][i][j] = dp[t ^ 1][i][j];
                if (i > 0 && j >= c)
                    dp[t][i][j] += dp[t][i - 1][j - c];
                dp[t][i][j] %= mod;
            }
        }
        t ^= 1;
    }

    int ans = 0;
    for (int i = 0; i <= b; i++)
        ans = (ans + dp[t ^ 1][m][i]) % mod;
    cout << ans;
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
