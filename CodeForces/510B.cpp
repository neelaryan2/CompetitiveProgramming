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
int n, m;
vector<char> col;
vector<int> vis;
bool chk(int u, int v) {
    int x1 = v / m, y1 = v % m;
    int x2 = u / m, y2 = u % m;
    if (x1 < 0 || x1 >= n) return false;
    if (y1 < 0 || y1 >= m) return false;
    if (x2 < 0 || x2 >= n) return false;
    if (y2 < 0 || y2 >= m) return false;
    if (col[u] != col[v]) return false;
    return abs(x1 - x2) + abs(y1 - y2) == 1;
}
void dfs(int v, int p = -1) {
    vis[v] = 1;
    int x = v / m, y = v % m;
    for (int u : {v - 1, v + 1, v - m, v + m}) {
        if (u == p) continue;
        if (!chk(v, u)) continue;
        if (vis[u]) {
            if (vis[u] == 1) {
                trace(col[u]);
                puts("Yes");
                exit(0);
            }
            continue;
        }
        dfs(u, v);
    }
    vis[v] = 2;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    col.resize(n * m);
    vis.assign(n * m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int v = i * m + j;
            cin >> col[v];
        }
    }
    for (int i = 0; i < n * m; i++)
        if (!vis[i]) dfs(i);
    puts("No");
}
