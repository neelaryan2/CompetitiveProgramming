#include<bits/stdc++.h>
using namespace std;

struct LCA {
	vector<int> par, depth;
	vector<vector<int>> P;
	vector<vector<int>> adj;
	LCA(int n) {
		adj.clear(); adj.resize(n);
	}
	void dfs(int v, int p = -1) {
		par[v] = p;
		for (int u : adj[v]) {
			if (u == p) continue;
			depth[u] = depth[v] + 1;
			dfs(u, v);
		}
	}
	void load() {
		int n = adj.size(), j = 0;
		for (; (1 << j) < n; j++);
		P.assign(n, vector<int>(j, -1));
		par.assign(n, -1);
		depth.assign(n, 0);
		dfs(0);
	}
	void build() {
		int N = par.size();
		for (int i = 0; i < N; i++)
			P[i][0] = par[i];
		for (int j = 1; (1 << j) < N; j++)
			for (int i = 0; i < N; i++)
				if (P[i][j - 1] != -1)
					P[i][j] = P[P[i][j - 1]][j - 1];
	}
	int query(int p, int q) {
		if (depth[p] < depth[q]) swap(p, q);
		int log = 1;
		for (; (1 << log) <= depth[p]; log++);

		for (int i = log - 1; i >= 0; i--)
			if (depth[p] - (1 << i) >= depth[q])
				p = P[p][i];
		if (p == q)	return p;
		for (int i = log - 1; i >= 0; i--)
			if (P[p][i] != -1 && P[p][i] != P[q][i])
				p = P[p][i], q = P[q][i];
		return par[p];
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	LCA lca = LCA(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		lca.adj[u].push_back(v);
		lca.adj[v].push_back(u);
	}
	lca.load();
	lca.build();
	while (m--) {
		bool no = false;
		int k; cin >> k;
		vector<int> q(k);
		int mx = -1, lowest = -1;
		for (int i = 0; i < k; i++) {
			cin >> q[i]; q[i]--;
			if (lca.depth[q[i]] > mx) {
				mx = lca.depth[q[i]];
				lowest = q[i];
			}
			if (lca.par[q[i]] != -1)
				q[i] = lca.par[q[i]];
		}
		for (int i = 0; i < k; i++) {
			int ancestor = lca.query(q[i], lowest);
			if (ancestor == q[i]) continue;
			no = true; break;
		}
		puts(no ? "NO" : "YES");
	}
}