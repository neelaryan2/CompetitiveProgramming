#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define fi first
#define se second
vector<int> a, ans;
vector<vector<int>> adj;
void dfs1(int v, int p = -1) {
	for (int u : adj[v]) {
		if (u == p) continue;
		dfs1(u, v);
		a[v] += max(0, a[u]);
	}
}
void dfs2(int v, int p = -1) {
	ans[v] = a[v];
	if (p != -1)
		ans[v] += max(0, ans[p] - max(0, a[v]));
	for (int u : adj[v]) {
		if (u == p) continue;
		dfs2(u, v);
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
	a.resize(n);
	ans.resize(n);
	adj.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = 2 * a[i] - 1;
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs1(0); dfs2(0);
	for (int i : ans) cout << i << " "; cout << endl;
}