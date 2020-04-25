#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
vector<vi> eq, neq;
vector<int> vis;
vector<int> comp;
bool cyc = false;
int T = 0;
void dfs(int v) {
    comp[v] = T;
    for (int u : eq[v]) {
        if (comp[u] != -1) continue;
        dfs(u);
    }
}
void dfs2(int v) {
    vis[v] = 1;
    for (int u : neq[v]) {
        if (vis[u] == 2)
            continue;
        else if (vis[u] == 1)
            cyc = true;
        else
            dfs2(u);
    }
    vis[v] = 2;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    eq.resize(n + m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == '=') {
                eq[i].pb(j + n);
                eq[j + n].pb(i);
            }
        }
    }
    comp.assign(n + m, -1);
    for (int i = 0; i < n + m; i++) {
        if (comp[i] == -1) {
            dfs(i);
            T++;
        }
    }
    neq.resize(T);
    vector<int> indeg(T, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '=') continue;
            int v = comp[i], u = comp[j + n];
            if (g[i][j] == '<') {
                neq[v].pb(u);
                indeg[u]++;
            } else {
                neq[u].pb(v);
                indeg[v]++;
            }
        }
    }
    vis.assign(T, 0);
    for (int i = 0; i < T; i++)
        if (!vis[i]) dfs2(i);
    if (cyc) {
        cout << "No\n";
        return 0;
    }
    vector<int> num(T, 1);
    bool found = true;
    while (found) {
        found = false;
        vis.assign(T, 0);
        for (int i = 0; i < T; i++) {
            if (indeg[i] != 0) continue;
            queue<int> q;
            q.push(i);
            num[i] = 1;
            vis[i] = 1;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u : neq[v]) {
                    if (num[v] + 1 > num[u]) {
                        num[u] = num[v] + 1;
                        found = true;
                    }
                    if (vis[u]) continue;
                    vis[u] = 1;
                    q.push(u);
                }
            }
        }
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        cout << num[comp[i]] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < m; i++) {
        cout << num[comp[i + n]] << ' ';
    }
    cout << '\n';
}