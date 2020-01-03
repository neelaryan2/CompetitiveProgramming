#include<bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define vi vector<int>

const int inf = 2e9;
vector<vi> adj;
vector<int> col, dist;
vector<bool> vis;
int val, ans = inf;

void bfs(int i) {
	queue<int> q;
	q.push(i); dist[i] = 0;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		vis[v] = true;
		for (int u : adj[v]) {
			if (vis[u]) continue;
			dist[u] = dist[v] + 1;
			if (col[u] == val) {
				ans = min(ans, dist[u]);
				return;
			}
			q.push(u);
		}
	}
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m; cin >> n >> m;
	adj.resize(n);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		adj[x].eb(y);
		adj[y].eb(x);
	}
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		col.eb(c); dist.eb(inf);
		vis.eb(false);
	}
	cin >> val;
	for (int i = 0; i < n; i++) {
		if (col[i] != val) continue;
		if (vis[i]) continue;
		bfs(i);
	}
	if (ans == inf) ans = -1;
	cout << ans << "\n";
}