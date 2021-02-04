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
const ll inf = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> v(n), c(n);
    for (int& e : v) cin >> e;
    for (int& e : c) cin >> e, e--;
    for (int _ = 0; _ < q; _++) {
        ll a, b;
        int mx1 = -1, mx2 = -1;
        cin >> a >> b;
        vector<ll> dp(n, 0), maxdp(n, -inf);
        for (int i = 0; i < n; i++) {
            if (mx1 != -1 && mx2 != -1)
                assert(c[mx1] != c[mx2]);
            dp[i] = b * v[i];
            if (mx1 != -1 && c[mx1] != c[i])
                dp[i] = max(dp[i], dp[mx1] + b * v[i]);
            if (mx2 != -1 && c[mx2] != c[i])
                dp[i] = max(dp[i], dp[mx2] + b * v[i]);
            if (maxdp[c[i]] != -inf)
                dp[i] = max(dp[i], maxdp[c[i]] + a * v[i]);
            trace(mx1, mx2);
            maxdp[c[i]] = max(maxdp[c[i]], dp[i]);
            if (mx1 == -1) {
                mx1 = i;
                continue;
            }
            if (c[mx1] == c[i]) {
                if (dp[mx1] < dp[i]) mx1 = i;
                continue;
            }
            if (mx2 == -1) {
                mx2 = i;
                continue;
            }
            if (c[mx2] == c[i]) {
                if (dp[mx2] < dp[i]) mx2 = i;
                continue;
            }
            if (dp[mx2] > dp[mx1]) swap(mx1, mx2);
            if (dp[mx1] < dp[i]) {
                mx2 = mx1;
                mx1 = i;
                continue;
            }
            if (dp[mx2] < dp[i]) {
                mx2 = i;
                continue;
            }
        }
        ll ans = 0;
        if (mx1 != -1) ans = max(ans, dp[mx1]);
        if (mx2 != -1) ans = max(ans, dp[mx2]);
        cout << ans << '\n'; 
    }
}
