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

const ll inf = 1e18;
using pli = pair<ll, int>;
vector<ll> dp[4];

void solve(int test) {
    int n, m;
    cin >> n >> m;
    vector<vector<pli>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].eb(w, v);
        adj[v].eb(w, u);
    }
    for (int i = 0; i < 4; i++)
        dp[i].assign(n, inf);

    priority_queue<pli> pq;
    pq.push(mp(0, 0));
    dp[0][0] = 0;

    while (!pq.empty()) {
        pli state = pq.top();
        pq.pop();
        int v = (state.se >> 2);
        int mask = (state.se & 3);
        state.fi *= -1;
        if (state.fi > dp[mask][v]) continue;
        for (int new_mask = 0; new_mask < 4; new_mask++) {
            if (new_mask & mask) continue;
            int nxt_mask = new_mask | mask;
            for (pli p : adj[v]) {
                pli new_state = mp(state.fi + p.fi, (p.se << 2) + nxt_mask);
                if (new_mask & 1) new_state.fi += p.fi;
                if (new_mask & 2) new_state.fi -= p.fi;
                if (dp[nxt_mask][p.se] > new_state.fi) {
                    dp[nxt_mask][p.se] = new_state.fi;
                    new_state.fi *= -1;
                    pq.push(new_state);
                }
            }
        }
    }

    for (int i = 1; i < n; i++)
        cout << dp[3][i] << ' ';
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
