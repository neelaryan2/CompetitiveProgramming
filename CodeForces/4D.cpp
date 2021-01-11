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
using ppi = pair<pii, int>;
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
    int n, w, h;
    cin >> n >> w >> h;
    vector<ppi> env;
    for (int i = 1; i <= n; i++) {
        pii p;
        cin >> p.fi >> p.se;
        if (p.fi <= w || p.se <= h)
            continue;
        env.eb(mp(p, i));
    }
    n = env.size();
    sort(all(env));

    vector<int> dp(n, 1), par(n, -1);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        pii pi = env[i].fi;
        for (int j = 0; j < i; j++) {
            pii pj = env[j].fi;
            if (pj.fi >= pi.fi || pj.se >= pi.se)
                continue;
            if (dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                par[i] = j;
            }
        }
        mx = max(mx, dp[i]);
    }
    int v = -1;
    for (int i = 0; i < n; i++)
        if (dp[i] == mx)
            v = i;

    vector<int> ans;
    while (v != -1) {
        ans.eb(env[v].se);
        v = par[v];
    }
    reverse(all(ans));
    cout << mx << '\n';
    for (int i : ans)
        cout << i << ' ';
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
