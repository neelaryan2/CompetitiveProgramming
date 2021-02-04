#include<bits/stdc++.h>
using namespace std;
vector<int> siz;
vector<bool> par;
vector<vector<int>> adj;
void dfs(int v, int p = -1) {
	for (int u : adj[v]) {
		if (u == p) continue;
		par[u] = !par[v];
		dfs(u, v);
		siz[v] += siz[u];
	}
}
int main() {
	int n, parcnt = 0; cin >> n;
	siz.resize(n, 1);
	par.resize(n, 1);
	adj.resize(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	long long ans = 0; dfs(0);
	for (int i = 0; i < n; i++) {
		ans += 1LL * siz[i] * (n - siz[i]);
		if (par[i]) parcnt++;
	}
	ans += 1LL * parcnt * (n - parcnt);
	cout << ans / 2 << endl;
}