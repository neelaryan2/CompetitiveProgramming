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
const int mod = 1e9 + 7;
void add(int& a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}
void solve(int test) {
    int n, l;
    cin >> n >> l;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    int dp[l + 1][n][2];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < n; i++) {
        if (a[i] <= l)
            dp[a[i]][i][0]++;
        if (a[i] != b[i] && b[i] <= l)
            dp[b[i]][i][1]++;
    }
    for (int i = 0; i <= l; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (k == j) continue;
                if (b[k] == a[j] && i >= a[j])
                    add(dp[i][j][0], dp[i - a[j]][k][0]);

                if (a[k] == a[j] && i >= a[j])
                    add(dp[i][j][0], dp[i - a[j]][k][1]);

                if (a[j] == b[j]) continue;

                if (b[k] == b[j] && i >= b[j])
                    add(dp[i][j][1], dp[i - b[j]][k][0]);

                if (a[k] == b[j] && i >= b[j])
                    add(dp[i][j][1], dp[i - b[j]][k][1]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        add(ans, dp[l][i][0]);
        add(ans, dp[l][i][1]);
    }
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
