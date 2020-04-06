#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define fi first
#define se second
const int k = 1;

int E, U, V;
vector<int> wei;
vector<bool> vis;
vector<vector<pii>> adj;
void dfs(int v) {
	vis[v] = true;
	for (pii u : adj[v]) {
		if (vis[u.fi]) continue;
		if (u.se == k - 1) continue;
		if (wei[u.se] >= E) continue;
		dfs(u.fi);
	}
}
bool check(int e) {
	E = e;
	int n = adj.size();
	vis.assign(n, false);
	dfs(U);
	return !vis[V];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	wei.resize(m);
	adj.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v >> wei[i];
		u--; v--;
		adj[u].emplace_back(make_pair(v, i));
		adj[v].emplace_back(make_pair(u, i));
		if (i != k - 1) continue;
		U = u; V = v;
	}
	int lo = 0, hi = 1e9 + 1, mid;
	while (lo < hi - 1) {
		mid = lo + (hi - lo) / 2;
		if (check(mid)) lo = mid;
		else hi = mid;
	}
	cout << lo << endl;
}