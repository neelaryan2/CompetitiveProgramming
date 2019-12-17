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
vi a; vector<pp> d;
vector<vi> adj;
bool com(pp a1, pp a2) {
	if (a1.fi != a2.fi) return a1.fi > a2.fi;
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	d.resize(n + 1); adj.resize(2 * n + 1); a.resize(n + 1);
	d[0] = mp(0, 0);
	forn(i, 1, n + 1) cin >> d[i].fi, d[i].se = i;
	sort(d.begin() + 1, d.end(), com);
	forn(i, 1, n + 1) a[i] = 2 * d[i].se - 1;
	forn(i, 1, n) adj[a[i]].pb(a[i + 1]);
	forn (i, 1, n + 1) 	{
		int ind = i + d[i].fi - 1;
		adj[2 * d[i].se].pb(a[ind]);
		if (ind == sz(a) - 1) a.pb(2 * d[i].se);
	}
	forn(i, 1, 2 * n + 1) for (int u : adj[i])
		cout << i << " " << u << endl;
	return 0;
}