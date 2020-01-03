#include<bits/stdc++.h>
using namespace std;

vector <vector<int>> g, gr;
vector<bool> used;
vector<int> order, mark, vis;
int curr = 0;
void dfs1 (int v) {
    used[v] = true;
    for (size_t i = 0; i < g[v].size(); ++i)
        if (!used[ g[v][i] ])
            dfs1 (g[v][i]);
    order.push_back(v);
}

void dfs2 (int v) {
    used[v] = true;
    mark[v] = curr;
    for (size_t i = 0; i < gr[v].size(); ++i)
        if (!used[ gr[v][i] ])
            dfs2(gr[v][i]);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m, s, ans = 0;
    cin >> n >> m >> s; s--;
    g.resize(n); gr.resize(n);
    vis.assign(n, 1); mark.assign(n, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        gr[b].push_back(a);
    }
    used.assign (n, false);
    for (int i = 0; i < n; ++i)
        if (!used[i])
            dfs1 (i);
    used.assign (n, false);
    for (int i = 0; i < n; ++i) {
        int v = order[n - 1 - i];
        if (!used[v]) {
            dfs2 (v);
            curr++;
        }
    }
    vis.assign(curr, 0);
    for (int v = 0; v < n; v++) {
        for (int u : g[v]) {
            if (mark[u] != mark[v]) {
                vis[mark[u]] = 1;
            }
        }
    }
    ans = accumulate(vis.begin(), vis.end(), 0);
    ans = curr - ans;
    if (vis[mark[s]] == 0) ans--;
    cout << ans << endl;
}