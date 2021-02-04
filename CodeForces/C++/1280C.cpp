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
#define pp pair<ll, ll>
#define vi vector<ll>
const ll N = 1e17;
ll t, k, x, y, w, G, B;
vector<vector<pp>> adj;
vi siz;
void dfs(ll v, ll p) {
	siz[v] = 1;
	for (pp edge : adj[v]) {
		ll u = edge.fi, wei = edge.se;
		if (u == p) continue;
		dfs(u, v); siz[v] += siz[u];
		if (siz[u] % 2) G += wei;
		B += wei * min(siz[u], k - siz[u]);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> k; k <<= 1; G = B = 0;
		adj.clear(); siz.clear();
		adj.resize(k); siz.resize(k);
		rep(i, k - 1) {
			cin >> x >> y >> w;
			x--, y--;
			adj[x].pb(mp(y, w));
			adj[y].pb(mp(x, w));
		}
		dfs(0, -1);
		cout << G << " " << B << endl;
	}
	return 0;
}