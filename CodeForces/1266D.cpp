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

#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define rall(v) (v).rbegin(), (v).rend()
#define pc(c) putchar(c)
#define gc(c) getchar(c)
#define put(s) fputs(s, stdout), putchar(' ')
#define br() putchar('\n')

#define popcnt __builtin_popcount
#define popcntll __builtin_popcountll
#define ctz __builtin_ctz
#define ctzll __builtin_ctzll
#define gcd __gcd

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
	putchar('\n');
}
inline ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-')f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}
const int N = 1e9 + 7;
const int mod = 998244353;

vl a;
set<pair<pi, ll>> ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n = read(), m = read(), u, v, d;
	a.rsz(n);
	rep(i, m) {
		u = read() - 1; v = read() - 1; d = read();
		a[u] += d; a[v] -= d;
	}
	v = 0;
	for (u = 0; u < n; u++) {
		if (a[u] <= 0) continue;
		while (a[u] != 0) {
			while (v < n && a[v] >= 0) v++;
			d = min(-a[v], a[u]);
			ans.ins(mp(mp(u + 1, v + 1), d));
			a[v] += d; a[u] -= d;
		}
	}
	cout << sz(ans) << endl;
	forv(i, ans) cout << i.fi.fi << " " << i.fi.se << " " << i.se << endl;
	return 0;
}