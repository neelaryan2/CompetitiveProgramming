#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
using ll = long long;
using pii = pair<ll, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll inf = 2e18;

vector<int> state, block, sums, pos, siz, par;
vector<vector<int>> adj;
void update(int i, int j) {
	int n = state.size();
	if (i > j) return;
	if (i < 0) return update(0, j);
	if (j >= n) return update(i, n - 1);
	int rt = sqrt(n);
	int ri = i / rt, rj = j / rt;
	if (ri == rj) {
		for (int it = i; it <= j; it++) {
			state[it] = 1 - state[it];
			int ch = 2 * state[it] - 1;
			sums[ri] += block[ri] ? -ch : ch;
		}
		return;
	}
	for (int it = ++ri; it < rj; it++) {
		sums[it] = rt - sums[it];
		block[it] = 1 - block[it];
	}
	update(i, ri * rt - 1);
	update(rj * rt, j);
}
int query(int i, int j) {
	int n = state.size();
	if (i > j) return 0;
	if (i < 0) return query(0, j);
	if (j >= n) return query(i, n - 1);
	int rt = sqrt(n);
	int ri = i / rt, rj = j / rt;
	int ans = 0;
	if (ri == rj) {
		for (int it = i; it <= j; it++)
			ans += block[ri] ? (1 - state[it]) : state[it];
		return ans;
	}
	for (int it = ++ri; it < rj; it++)
		ans += sums[it];
	ans += query(i, ri * rt - 1);
	ans += query(rj * rt, j);
	return ans;
}
int T = 0;
void dfs(int v, int p = -1) {
	pos[v] = T++;
	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v);
		siz[v] += siz[u];
	}
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	adj.resize(n);
	par.assign(n, -1);
	siz.assign(n, 1);
	pos.resize(n);
	for (int i = 1; i < n; i++) {
		int u; cin >> u; u--;
		par[i] = u;
		adj[i].emplace_back(u);
		adj[u].emplace_back(i);
	}
	dfs(0);
	int rt = sqrt(n);
	int sz = (rt * rt == n) ? rt : rt + 1;
	block.assign(rt + 1, 0);
	sums.assign(rt + 1, 0);
	state.assign(n, 0);
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		state[pos[i]] = t;
	}
	for (int i = 0; i <= rt; i++) {
		for (int j = i * rt; j < min((i + 1)*rt, n); j++) {
			sums[i] += state[j];
		}
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		string s; cin >> s;
		int v; cin >> v; v--;
		if (s == "get") cout << query(pos[v], pos[v] + siz[v] - 1) << endl;
		if (s == "pow") update(pos[v], pos[v] + siz[v] - 1);
	}
}