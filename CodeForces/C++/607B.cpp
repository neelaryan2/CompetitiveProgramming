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
    int n;
    cin >> n;
    vector<int> a(n); 
    for (int& e : a) cin >> e;
    int dp[n][n];
    for (int len = 1 - n; len < n; len++) {
        for (int l = max(-len, 0); l < min(n, n - len); l++) {
            int r = l + len;
            if (len < -1)
                dp[l][r] = 0;
            else if (len < 1)
                dp[l][r] = 1;
            else {
                dp[l][r] = 1e9;
                for (int i = l; i < r; i++)
                    dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r]);
                if (a[l] == a[r])
                    dp[l][r] = min(dp[l][r], dp[l + 1][r - 1]);
            }
        }
    }
    int ans = dp[0][n - 1];
    cout << ans << '\n';
}
