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
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-')f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}
//------------------------------------- end ---------------------------------------//
const int N = 200005;
const int mod = 998244353;
vi par, siz;
vl ans(N, 0);
vector<pair<int, pi>> edges;
int root(int v) {
	return (v == par[v]) ? v : par[v] = root(par[v]);
}
void merge(pair<int, pi> edge) {
	int a = root(edge.se.fi), b = root(edge.se.se);
	ans[edge.fi] += 1LL * siz[a] * siz[b];
	if (a == b) return;
	if (a < b) swap(a, b);
	siz[a] += siz[b];
	par[b] = a;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n = read(), m = read(), u, v, w;
	rep(i, n) par.eb(i), siz.eb(1);
	rep(i, n - 1) {
		u = read() - 1; v = read() - 1; w = read();
		edges.eb(mp(w, mp(u, v)));
	}
	sort(all(edges));
	rep(i, n - 1) merge(edges[i]);
	rep(i, N - 1) ans[i + 1] += ans[i];
	rep(i, m) cout << ans[read()] << " \n"[i == m - 1];
	return 0;
}