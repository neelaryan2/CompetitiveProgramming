#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define eb emplace_back

const int maxn = 5e4 + 5;
int n, root = 0; ll tot, ans;
vector<ll> sums(maxn);
vector<vector<int>> adj;
set<ll> path, done;

inline bool has(set<ll>& s, ll val) {
	return (s.find(val) != s.end());
}
void sizes(int v, int p = -1) {
	for (int u : adj[v]) {
		if (u == p) continue;
		sizes(u, v);
		sums[v] += sums[u];
	}
}
void dfs(int v, int p = -1) {
	ll curr = sums[v];
	if (3 * curr >= tot) {
		if (has(done, curr) ||
		        has(done, tot - 2 * curr) ||
		        has(path, 2 * curr) ||
		        has(path, tot - curr))
			ans = min(ans, (3 * curr - tot));
	}
	ll temp = (tot - curr) / 2;
	if ((tot - curr) % 2 == 0 && temp >= curr) {
		if (has(done, temp) || has(path, temp + curr))
			ans = min(ans, (temp - curr));
	}
	path.insert(curr);
	for (int u : adj[v])
		if (u != p) dfs(u, v);
	path.erase(curr);
	done.insert(curr);
}
inline void init() {
	done.clear();
	adj.assign(n + 1, vector<int>());
	adj[root].eb(n);
	adj[n].eb(root);
	sums[n] = 0;
}
inline void solve() {
	cin >> n; init();
	for (int i = 0; i < n; i++)
		cin >> sums[i];
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		adj[x].eb(y);
		adj[y].eb(x);
	}
	sizes(root);
	ans = tot = sums[root];
	dfs(root);
	if (ans == tot) ans = -1;
	cout << ans << endl;
}
int main() {
	int q; cin >> q;
	while (q--) solve();
}