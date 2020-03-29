#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	map<vector<int>, vector<int>> cnt;
	for (int i = 0; i < n; i++) {
		sort(adj[i].begin(), adj[i].end());
		cnt[adj[i]].emplace_back(i);
	}
	if (cnt.size() != 3) {
		cout << -1 << endl;
		return 0;
	}
	for (auto p : cnt) {
		if (!p.first.empty()) continue;
		cout << -1 << endl;
		return 0;
	}
	vector<int> comp(n);
	int i = 1;
	for (auto p : cnt) {
		for (int v : p.second)
			comp[v] = i;
		i++;
	}
	for (int i : comp) cout << i << " ";
	cout << endl;
}