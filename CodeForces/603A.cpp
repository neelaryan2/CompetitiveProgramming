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
    string s;
    cin >> s;
    vector<int> dp[3];
    for (int i = 0; i < 3; i++)
        dp[i].assign(n, 1);
    for (int i = 1; i < n; i++) {
        dp[0][i] = dp[0][i - 1] + (s[i] != s[i - 1]);
        dp[1][i] = max(dp[1][i - 1] + (s[i] != s[i - 1]), dp[0][i - 1] + (s[i] == s[i - 1]));
        dp[2][i] = max(dp[2][i - 1] + (s[i] != s[i - 1]), dp[1][i - 1] + (s[i] == s[i - 1]));
    }
    int ans = -1;
    for (int i = 0; i < 3; i++)
        ans = max(ans, dp[i].back());
    cout << ans << '\n';
}
