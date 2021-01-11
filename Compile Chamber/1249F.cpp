#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
const int inf = 1e9;
vector<int> siz, par, edges, rnk;
vector<ll> wei;
vector<vector<int>> adj, dist;
void init(int n) {
	siz.assign(n, 1);
	par.assign(n, -1);
	edges.assign(n, 0);
	rnk.assign(n, 0);
	wei.resize(n);
	adj.resize(n);
	dist.resize(n);
}
void bfs(int s) {
	int n = dist.size();
	queue<int> q;
	dist[s].assign(n, inf);
	dist[s][s] = 0;
	vector<bool> vis(n, false);
	vis[s] = true;
	q.push(s);
	while (!q.empty()) {
		int v =  q.front(); q.pop();
		for (int u : adj[v]) {
			if (vis[u]) continue;
			dist[s][u] = dist[s][v] + 1;
			vis[u] = true; q.push(u);
		}
	}
}
int root(int a) {
	if (par[a] == -1) par[a] = a;
	int _a = a;
	while (a != par[a]) a = par[a];
	par[_a] = a;
	return a;
}
void add(int a, int b) {
	a = root(a); b = root(b);
	if (a == b) {
		edges[a]++;
		return;
	}
	if (rnk[a] < rnk[b]) swap(a, b);
	siz[a] += siz[b];
	wei[a] += wei[b];
	edges[a] += edges[b] + 1;
	par[b] = a;
	rnk[a]++;
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	init(n);
	for (int i = 0; i < n; i++)
		cin >> wei[i];

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	for (int i = 0; i < n; i++)
		bfs(i);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << dist[i][j] << " ";
		cout << endl;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i != j && dist[i][j] > k) {
				cout << i + 1 << ' ' << j + 1 << endl;
				add(i, j);
			}
		}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int r = root(i);
		ll c = siz[r];
		c *= c - 1;
		if (edges[r] == c)
			ans = max(ans, wei[r]);
	}
	trace(ans);
	cout << ans << endl;
}