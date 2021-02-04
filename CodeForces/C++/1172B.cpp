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
#define vi vector<int>
#define endl "\n"
const int N = int(1e9);
int n, x, y; const ll mod = 998244353;
vector<ll> fact;
vector<vi> adj;
ll dfs(int v, int p) {
	ll ans = fact[sz(adj[v])];
	for (int u : adj[v]) 	if (u != p) ans = (ans * dfs(u, v)) % mod;
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	fact.resize(n + 1, 1); adj.resize(n);
	rep(i, n - 1) {
		cin >> x >> y;
		x--, y--;
		adj[x].pb(y); adj[y].pb(x);
	}
	rep(i, n) fact[i + 1] = ((i + 1) * fact[i]) % mod;
	ll ans = (n * dfs(0, -1)) % mod;
	cout << ans << endl;
	return 0;
}