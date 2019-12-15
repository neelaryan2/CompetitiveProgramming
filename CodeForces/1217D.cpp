#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, a, b) for (int i = a; i < b; i++)
#define rfor(i, b, a) for (int i = b; i > a; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n - 1; i >=0; i--)
#define forv(i, v) for (auto i = v.begin(); i != v.end(); i++)
#define all(v) v.begin(), v.end()
#define sz(v) int(v.size())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define pp pair<int, int>
const int N = int(1e9);
int n, m, x, y, cycle = 1;
vector<vector<pp>> adj;
vector<int> state, ans;

void dfs(int v) {
	state[v] = 1;
	for (pp p : adj[v]) {
		if (state[p.fi] == 0) ans[p.se] = 1, dfs(p.fi);
		else if (state[p.fi] == 1) cycle = 2, ans[p.se] = 2;
		else ans[p.se] = 1;
	}
	state[v] = 2;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m; state.resize(n);
	adj.resize(n); ans.resize(m);
	rep(i, n) state[i] = 0;
	rep(i, m) cin >> x >> y, adj[x - 1].pb(mp(y - 1, i));
	rep(i, n) if (!state[i]) dfs(i);
	cout << cycle << endl;
	rep(i, m) cout << ans[i] << " ";
	cout << endl;
	return 0;
}