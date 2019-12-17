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
int n, x, y;
vi a; vector<vi> adj;
int gcd(int a, int b) {
	if (!a) return b;
	if (a > b) return gcd(a % b, b);
	else return gcd(b % a, a);
}
void dfs(int v, int p, int gcdsofar) {
	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v, gcd(gcdsofar, a[v]));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n; a.resize(n); adj.resize(n);
	rep(i, n) cin >> a[i];
	rep(i, n - 1) {
		cin >> x >> y;
		x--, y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(0, -1, a[0]);


	return 0;
}