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

vector<vi> adj;
int ans, p1, p2;

int bfs(int s) {
    int n = adj.size();
    queue<int> q;
    vector<int> dist(n, inf);
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (dist[u] != inf) continue;
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }
    int mx = -1, ret = -1;
    for (int i = 0; i < n; i++)
        if (dist[i] != inf && dist[i] > mx)
            mx = dist[i], ret = i;
    return ret;
}
pii dfs(int v, int p, int d) {
    if (adj[v].size() == (p != -1))
        return mp(0, v);
    vector<pii> vec(1, mp(0, p));
    for (int u : adj[v]) {
        if (u == p) continue;
        pii cur = dfs(u, v, d + 1);
        cur.fi++;
        vec.eb(cur);
    }
    int k = vec.size() - 1;
    sort(all(vec));
    int cur = d + vec[k].fi + vec[k - 1].fi;
    if (cur > ans) {
        ans = cur;
        p1 = vec[k].se;
        p2 = vec[k - 1].se;
    }
    return vec[k];
}

void solve(int test) {
    int n;
    cin >> n;
    if (n == 3) {
        cout << "2\n1 2 3";
        return;
    }
    adj.assign(n, {});
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[v].eb(u);
        adj[u].eb(v);
    }
    int root = bfs(bfs(0));
    ans = 0, p1 = -1, p2 = -1;
    dfs(root, -1, 0);
    cout << ans << '\n';
    root++, p1++, p2++;
    cout << root << ' ' << p1 << ' ' << p2;
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
