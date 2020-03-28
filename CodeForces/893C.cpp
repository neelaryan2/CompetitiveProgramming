#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> vis;
vector<int> c;
vector<vector<int>> adj;

int dfs(int v) {
	vis[v] = true;
	int ans = c[v];
	for (int u : adj[v]) {
		if (vis[u]) continue;
		ans = min(ans, dfs(u));
	}
	return ans;
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	vis.assign(n, false);
	adj.resize(n);
	c.resize(n);
	for (int i = 0; i < n; i++)
		cin >> c[i];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		ans += dfs(i);
	}
	cout << ans << endl;
}