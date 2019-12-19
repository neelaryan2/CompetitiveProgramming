#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pl> vpl;

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
#define put(s) fputs(s, stdout)

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
inline void read(T &x) {
	bool neg = false; register T c; x = 0;
	c = gc();
	if (c == '-') {neg = true; c = gc();}
	for (; (c > 47 && c < 58); c = gc())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg) x *= -1;
}
template <typename T>
inline void write(T y) {
	if (y == 0) { pc('0'); pc(' '); return ;}
	if (y < 0) y = -y, pc('-');
	T rev = y;
	int count = 0;
	while ((rev % 10) == 0) { count++; rev /= 10;}
	rev = 0;
	while (y != 0) { rev = (rev << 3) + (rev << 1) + y % 10; y /= 10;}
	while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
	while (count--) pc('0');
	pc(' ');
}

const int N = 1e9 + 7;
const int mod = 998244353;
int counter = 1, root = 0;
vi l, r;
vector<vi> adj;
void dfs(int v, int p) {
	r[v] = counter = counter + sz(adj[v]) + (v == root);
	int cou = 0;
	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v); cou++;
		l[u] = r[v] - cou;
	}
}
int main() {
	int n, x, y; read(n);
	l.rsz(n); r.rsz(n); adj.rsz(n);
	rep(i, n - 1) {
		read(x), x--;
		read(y), y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	l[0] = 1; dfs(root, -1);
	rep(i, n) write(l[i]), write(r[i]), pc('\n');
	return 0;
}