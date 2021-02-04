#include<bits/stdc++.h>
using namespace std;

using vi = vector<int>;
vi vis;
vector<vi> adj;
bool cyc;

void dfs(int v, int p = -1) {
	vis[v] = 1;
	for (int u : adj[v]) {
		if (u == p) continue;
		if (vis[u] == 2) continue;
		if (vis[u] == 1) cyc = true;
		else dfs(u, v);
	}
	vis[v] = 2;
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	adj.resize(n);
	vis.assign(n, 0);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (vis[i] != 0) continue;
		cyc = false; dfs(i);
		ans += cyc ? 0 : 1;
	}
	cout << ans << endl;
}