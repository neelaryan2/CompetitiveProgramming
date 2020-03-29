#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
#define fi first
#define se second
const ll inf = 1e18;

vector<int> pos, dfs_num, siz;
vector<vector<int>> adj;
int T = 0;
void dfs(int v, int p = -1) {
	dfs_num[v] = T;
	pos[T++] = v;
	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v);
		siz[v] += siz[u];
	}
}
int query(int u, int k) {
	if (k >= siz[u]) return -1;
	return 1 + pos[k + dfs_num[u]];
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, q;
	cin >> n >> q;
	adj.resize(n); siz.assign(n, 1);
	dfs_num.resize(n); pos.resize(n);
	for (int i = 1; i < n; i++) {
		int p; cin >> p; p--;
		adj[i].emplace_back(p);
		adj[p].emplace_back(i);
	}
	dfs(0);
	while (q--) {
		int u, k;
		cin >> u >> k;
		u--; k--;
		cout << query(u, k) << endl;
	}
}