#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> ans;
vector<vector<int>> adj;
void bfs(int s) {
	int n = adj.size();
	vector<bool> vis(n, false);
	queue<int> q;
	vis[s] = true;
	q.push(s);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int u : adj[v]) {
			if (vis[u]) continue;
			ans.emplace_back(make_pair(v + 1, u + 1));
			vis[u] = true; q.push(u);
		}
	}
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	adj.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	int mx = -1, root = -1;
	for (int i = 0; i < n; i++) {
		int curr = adj[i].size();
		if (mx >= curr) continue;
		mx = curr;
		root = i;
	}
	bfs(root);
	for (auto p : ans)
		cout << p.first << " " << p.second << endl;
}