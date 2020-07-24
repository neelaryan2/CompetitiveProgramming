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
vector<string> g;
vector<int> order;
void bfs(int sx, int sy) {
    const int inf = 1e9;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    int n = g.size(), m = g[0].size();
    queue<int> q;
    vector<bool> vis(n * m, false);
    vector<int> dist(n * m, inf);
    int s = sx * m + sy;
    q.push(s);
    vis[s] = true;
    dist[s] = 0;
    trace(n*m);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        order.eb(v);
        int xx = v / m, yy = v % m;
        for (int t = 0; t < 4; t++) {
            int x = xx + dx[t];
            int y = yy + dy[t];
            if (x < 0 || x >= n) continue;
            if (y < 0 || y >= m) continue;
            int u = x * m + y;
            if (vis[u] || g[x][y] == '#') continue;
            q.push(u);
            dist[u] = dist[v] + 1;
            vis[u] = true;
        }
    }
    trace(dist);
}
void solve(int test) {
    int n, m, k;
    cin >> n >> m >> k;
    g.resize(n);
    for (string& e : g)
        cin >> e;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.') {
                bfs(i, j);
                reverse(all(order));
                for (int t = 0; t < k; t++) {
                    int v = order[t];
                    int x = v / m, y = v % m;
                    g[x][y] = 'X';
                }
                for (string& e : g) 
                    cout << e << '\n';
                return;
            }
        }
    }
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