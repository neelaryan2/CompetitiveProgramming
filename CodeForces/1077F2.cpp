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
    int n, k, x;
    cin >> n >> k >> x;

    ll dp[n + 1][x + 1];
    int a[n];
    vector<deque<int>> q(x + 1);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= x; j++)
            dp[i][j] = -1e18;

    dp[0][0] = 0;
    q[0].push_back(0);
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, x); j >= 0; j--) {
            if (j > 0) {
                int ii = q[j - 1].front();
                dp[i][j] = dp[ii][j - 1] + a[i - 1];
            }
            while (!q[j].empty() && q[j].front() <= i - k)
                q[j].pop_front();
            while (!q[j].empty() && dp[q[j].back()][j] <= dp[i][j])
                q[j].pop_back();
            q[j].push_back(i);
        }
    }
    ll ans = -1;
    for (int i = n - k + 1; i <= n; i++)
        ans = max(ans, dp[i][x]);
    cout << ans;
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= x; j++)
    //         cerr << (dp[i][j] < 0 ? "-" : to_string(dp[i][j])) << ' ';
    //     cerr << endl;
    // }
    // cerr << endl;
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= x; j++)
    //         cerr << (par[i][j] < 0 ? "-" : to_string(par[i][j])) << ' ';
    //     cerr << endl;
    // }
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
