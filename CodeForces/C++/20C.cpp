#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int, int> pi;
typedef pair<long long, long long> pl;
typedef pair<long double, long double> pd;

typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<long double> vd;
typedef vector<string> vs;
typedef vector<pair<ll, ll>> vpl;

#define forn(i, a, b) for (int i = (a); i < (b); i++)
#define rfor(i, b, a) for (int i = (b); i > (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forv(i, v) for (auto& (i) : (v))
#define trav(i, v) for (auto i = (v).begin(); i != (v).end(); i++)

#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define rall(v) (v).rbegin(), (v).rend()
#define pc(c) putchar(c)
#define gc(c) getchar(c)
#define br() cout << endl

#define popcnt __builtin_popcount
#define popcntll __builtin_popcountll
#define ctz __builtin_ctz
#define ctzll __builtin_ctzll

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define ef emplace_front
#define eb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define rsz resize
#define ins insert
#define endl "\n"

#define Set(n, i) n = (n) | (1LL << (i))
#define Reset(n, i) n = (n) & ~(1LL << (i))
#define Test(n, i) ((n) >> (i) & 1LL)
#define par(n) (n) & 1LL

template <typename T>
inline void pv(vector<T> v) {
	for (T x : v) cout << x << " ";
	cout << endl;
}
inline ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-')f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}
//------------------------------------- end ---------------------------------------//
const int N = 1e9 + 7;
const int mod = 998244353;
vector<ll> dist, parent, ans;
vector<vector<pair<ll, ll>>> adj;
void dijkstra(ll s, ll n) {
	using pi = pair<ll, ll>;
	priority_queue<pi> pq;
	dist.resize(n, 1e18);
	parent.resize(n, -1);
	pq.push(mp(0, s));	dist[s] = 0;
	while (!pq.empty()) {
		ll v = pq.top().se;
		ll d = -pq.top().fi;
		pq.pop();
		if (d > dist[v]) continue;
		for (pi p : adj[v]) {
			ll u = p.fi, w = p.se;
			if (dist[v] + w < dist[u]) {
				dist[u] = dist[v] + w;      // update the distance
				parent[u] = v;        // for extracting the shortest path
				pq.push({ -dist[u], u});
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n = read(), m = read(), u, v, w;
	adj.rsz(n);
	rep(i, m) {
		u = read() - 1; v = read() - 1; w = read();
		adj[u].eb(mp(v, w));
		adj[v].eb(mp(u, w));
	}
	dijkstra(0, n);
	if (dist[n - 1] == 1e18) {cout << "-1\n"; return 0;}
	v = n - 1;
	while (v) ans.eb(v), v = parent[v];
	ans.eb(0); reverse(all(ans));
	rep(i, sz(ans)) cout << ++ans[i] << " \n"[i == sz(ans) - 1];
	return 0;
}