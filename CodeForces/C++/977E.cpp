#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define fi first
#define se second
#define eb emplace_back

#define vi vector<int>
#define sz(v) int((v).size())

vector<vi> adj;
vector<bool> vis;
bool dfs(int v) {
	vis[v] = true;
	bool ans = (adj[v].size() == 2);
	for (int u : adj[v]) {
		if (vis[u]) continue;
		bool b = dfs(u);
		ans = ans && b;
	}
	return ans;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m; cin >> n >> m;
	adj.resize(n);
	vis.resize(n, false);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].eb(v);
		adj[v].eb(u);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		bool b = dfs(i);
		// cout << i + 1 << " " << b << endl;
		ans += b;
	}
	cout << ans << endl;
}