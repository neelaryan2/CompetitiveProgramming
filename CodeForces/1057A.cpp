#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> par;
vector<vector<int>> adj;
void dfs(int v, int p = -1) {
	par[v] = p;
	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v);
	}
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	adj.resize(n);
	par.assign(n, -1);
	vector<int> path;
	for (int i = 1; i < n; i++) {
		int u; cin >> u; u--;
		adj[u].emplace_back(i);
		adj[i].emplace_back(u);
	}
	dfs(0);
	int v = n - 1;
	while (v != -1) {
		path.emplace_back(v);
		v = par[v];
	}
	reverse(path.begin(), path.end());
	for (int i : path) cout << i + 1 << " "; cout << endl;
}
