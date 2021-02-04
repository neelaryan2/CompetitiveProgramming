#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
const ll inf = 2e18;

vector<vector<pii>> adj;
vector<ll> wei, dist;
vector<int> ans;

void dijkstra(int s) {
	set<pli> q;
	int n = adj.size();
	dist.assign(n, inf);
	dist[s] = 0;
	for (int i = 0; i < n; i++)
		q.insert({dist[i], i});
	while (!q.empty()) {
		int v =  q.begin()->se;
		q.erase(q.begin());
		for (pii u : adj[v]) {
			if (dist[v] + wei[u.se] > dist[u.fi]) continue;
			if (dist[v] + wei[u.se] == dist[u.fi] && wei[u.se] >= wei[ans[u.fi]]) continue;
			q.erase({dist[u.fi], u.fi});
			dist[u.fi] = dist[v] + wei[u.se];
			ans[u.fi] = u.se;
			q.insert({dist[u.fi], u.fi});
		}
	}
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	adj.resize(n);
	wei.resize(m);
	ans.assign(n, m);
	for (int i = 0; i < m; i++) {
		int ui, vi, w;
		cin >> ui >> vi >> w;
		ui--; vi--;
		wei[i] = w;
		pii u = {ui, i};
		pii v = {vi, i};
		adj[ui].emplace_back(v);
		adj[vi].emplace_back(u);
	}
	int s; cin >> s; s--;
	dijkstra(s);
	ll tot = 0;
	for (int i = 0; i < n; i++)
		if (i != s)	tot += wei[ans[i]];
	cout << tot << endl;
	for (int i = 0; i < n; i++)
		if (i != s) cout << ans[i] + 1 << " ";
	cout << endl;
}