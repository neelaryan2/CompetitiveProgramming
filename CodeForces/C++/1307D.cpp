#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;

vector<bool> special;
vector<vector<int>> adj;
vector<int> d1, d2;
int ans;

void bfs(int s, vector<int>& dist)  {
	queue<int> q;
	int n = adj.size();
	vector<bool> vis(n, false);
	dist.assign(n, inf);

	vis[s] = true;
	dist[s] = 0;
	q.push(s);

	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int u : adj[v]) {
			if (vis[u]) continue;
			vis[u] = true;
			dist[u] = dist[v] + 1;
			q.push(u);
		}
	}
}
bool cmp(pii p1, pii p2) {
	return p1.first + p2.second < p2.first + p1.second;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	adj.resize(n);
	special.assign(n, false);
	for (int i = 0; i < k; i++) {
		int u; cin >> u;
		special[u - 1] = true;
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	bfs(0, d1); bfs(n - 1, d2);
	vector<pii> d;
	for (int i = 0; i < n; i++)
		if (special[i])
			d.emplace_back(make_pair(d1[i], d2[i]));
	sort(d.begin(), d.end(), cmp);
	int mx = -inf;
	for (pii p : d) {
		ans = max(ans, p.second + mx + 1);
		mx = max(mx, p.first);
	}
	ans = min(ans, d1.back());
	cout << ans << endl;
}