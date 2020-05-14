#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vb = vector<bool>;
using vpi = vector<pii>;
using vl = vector<ll>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const ll inf = 1e18;
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, -1, 0, 1};
vector<vi> adj;
vector<int> ans;
vector<bool> visit;
vector<vl> res;

bool bfs(int s, int t, vi& par) {
    int n = res.size();
    vector<bool> visited(n, false);
    par.assign(n, -1);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u = 0; u < n; u++) {
            if (!visited[u] && res[v][u] > 0) {
                q.push(u);
                par[u] = v;
                visited[u] = true;
            }
        }
    }
    return visited[t];
}
void dfs(int v) {
    visit[v] = true;
    for (int u = 0; u < res.size(); u++)
        if (res[v][u] && !visit[u])
            dfs(u);
}
ll minCut(int s, int t) {
    int n = adj.size();
    res.clear();
    res.assign(n, vl(n, 0));
    vector<int> par;
    for (int v = 0; v < n; v++)
        for (int u = 0; u < n; u++)
            res[u][v] = adj[u][v];
    ll mncut = 0;
    while (bfs(s, t, par)) {
        ll path_flow = inf;
        for (int v = t; v != s; v = par[v]) {
            int u = par[v];
            path_flow = min(path_flow, res[u][v]);
        }
        for (int v = t; v != s; v = par[v]) {
            int u = par[v];
            res[u][v] -= path_flow;
            res[v][u] += path_flow;
        }
        par.clear();
        mncut += path_flow;
    }
    visit.clear();
    visit.assign(n, false);
    dfs(s);
    for (int i = 0; i < n; i++)
        if (visit[i])
            ans[i] = -1;
    return mncut;
}
void solve() {
    int h, w, n;
    cin >> h >> w >> n;
    adj.clear();
    adj.assign(n + 2, vi(n + 2, 0));
    ans.assign(n + 2, 1);
    vector<pii> vec(n);
    vector<int> hval(n), pval(n);
    vector<vi> val(h, vi(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> val[i][j];
    for (int i = 0; i < n; i++) {
        int x, y, p;
        cin >> x >> y >> p;
        --x, --y;
        hval[i] = val[x][y];
        pval[i] = p;
        vec[i] = {x, y};
    }
    auto check = [&](int i, int j) {
        pii p1 = vec[i], p2 = vec[j];
        if (p1.fi == p2.fi)
            return abs(p1.se - p2.se) == 1;
        else if (p1.se == p2.se)
            return abs(p1.fi - p2.fi) == 1;
        return false;
    };
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!check(i, j)) continue;
            int w = pval[i] * pval[j];
            adj[i + 1][j + 1] = w;
            adj[j + 1][i + 1] = w;
            tot += w;
        }
    }
    for (int i = 0; i < n; i++) {
        if (hval[i] < 0) {
            int cur = -hval[i] * pval[i];
            adj[0][i + 1] = cur;
            tot += cur;
        } else if (hval[i] > 0) {
            int cur = hval[i] * pval[i];
            adj[i + 1][n + 1] = cur;
            tot += cur;
        }
    }
    ll mn = minCut(0, n + 1);
    ll fin = tot - 2 * mn;
    cout << fin << '\n';
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}