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
const int mod = 1e9 + 7;
void solve(int test) {
    int n;
    cin >> n;
    vector<int> p(n + 1, 0), dp(n + 1, 0), pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        dp[i] = (1 + (i - p[i]) + pref[i - 1] - pref[p[i] - 1]) % mod;
        if (dp[i] < 0) dp[i] += mod;
        pref[i] = (pref[i - 1] + dp[i]) % mod;
    }
    int ans = (pref[n] + n) % mod;
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
