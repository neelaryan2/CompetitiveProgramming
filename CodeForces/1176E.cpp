#include<bits/stdc++.h>
using namespace std;


void dfs(int v, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& chosen) {
	vis[v] = true;
	bool has = false;
	for (int u : adj[v])
		has = has || chosen[u];
	if (!has && !chosen[v])
		chosen[adj[v][0]] = true;
	for (int u : adj[v])
		if (!vis[u]) dfs(u, adj, vis, chosen);
}

inline void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n);
	vector<bool> vis(n, false), chosen(n, false);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0, adj, vis, chosen);
	int sz = accumulate(chosen.begin(), chosen.end(), 0);
	if (sz <= n / 2) cout << sz << endl;
	else cout << n - sz << endl;
	for (int i = 0; i < n; i++) {
		if (chosen[i] && sz <= n / 2)
			cout << i + 1 << " ";
		if (!chosen[i] && sz > n / 2)
			cout << i + 1 << " ";
	}
	cout << endl;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) solve();
}