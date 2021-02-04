#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int sz, root;
vector<vector<int>> adj;
vector<int> par, siz;
vector<int> one, two;

void dfs(int v) {
	for (int u : adj[v]) {
		if (u == par[v]) continue;
		dfs(u); siz[v] += siz[u];
	}
}
bool dfs2(int v) {
	bool found = false;
	for (int u : adj[v]) {
		if (u == par[v]) continue;
		if (siz[u] == sz) found = true;
		bool  b = dfs2(u);
		found = found || b;
	}
	if (v == root) return found;
	if (!found && siz[v] == sz) one.emplace_back(v);
	if (found && siz[v] == 2 * sz) two.emplace_back(v);
	return found;
}
int dfs3(int v) {
	bool found = false;
	for (int u : adj[v]) {
		if (u == par[v]) continue;
		if (siz[u] == sz) return u;
		int tm = dfs3(u);
		if (tm != -1) return tm;
	}
	return -1;
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
	par.resize(n);
	adj.resize(n);
	siz.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> par[i] >> siz[i];
		if (--par[i] == -1) {root = i; continue;}
		adj[i].emplace_back(par[i]);
		adj[par[i]].emplace_back(i);
	}
	dfs(root);
	if (siz[root] % 3) {
		cout << -1 << endl;
		return 0;
	}
	sz = siz[root] / 3;
	dfs2(root);
	if (one.size() >= 2) {
		cout << one[0] + 1 << " " << one[1] + 1 << endl;
		return 0;
	}
	if (!two.empty()) {
		int v = dfs3(two[0]);
		cout << two[0] + 1 << " " << v + 1 << endl;
		return 0;
	}
	cout << -1 << endl;
}