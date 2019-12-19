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

#define forn(i, a, b) for (int i = a; i < b; i++)
#define rfor(i, b, a) for (int i = b; i > a; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define forv(i, v) for (auto& i : v)

#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define rall(v) v.rbegin(), v.rend()

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

#define Set(n, i) n = n | (1LL << i)
#define Reset(n, i) n = n & ~(1LL << i)
#define Test(n, i) (n >> i & 1LL)
#define par(n) n & 1LL

template <typename T>
inline T maxm(T v) { return v;}
template <typename T, typename... Types>
inline T maxm(T v, Types... u) {return max(v, maxm(u...));}

template <typename T>
inline T minm(T v) { return v;}
template <typename T, typename... Types>
inline T minm(T v, Types... u) {return min(v, minm(u...));}

template <typename T>
inline void print(T v) { cout << v << "\n";}
template <typename T, typename... Types>
inline void print(T v, Types... u) {cout << v << " " ; print(u...) ;}

template <typename T>
inline void read(T &x) {
	bool neg = false; register T c; x = 0;
	c = getchar();
	if (c == '-') {neg = true; c = getchar();}
	for (; (c > 47 && c < 58); c = getchar())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg) x *= -1;
}
const int N = 1e9 + 7;
const int mod = N;
int n, q, a, b, l, r;
vector<ll> f, x, p;
inline void update(int l, int r) {
	if (l < 0 || r >= n || l > r) return;
	if (l == r) {x[l] = (x[l] + f[0]) % mod; return;}
	p[l] = (p[l] + f[0]) % mod;
	p[l + 1] = (p[l + 1] + f[1] - b * f[0]) % mod;
	p[r + 1] = (p[r + 1] - f[r - l + 1]) % mod;
	p[r + 2] = (p[r + 2] - a * f[r - l]) % mod;
	if (p[l + 1] < 0) p[l + 1] += mod;
	if (p[r + 1] < 0) p[r + 1] += mod;
	if (p[r + 2] < 0) p[r + 2] += mod;
}
int main() {
	read(n), read(q);
	f.rsz(n); x.rsz(n); p.rsz(n + 2, 0);
	read(f[0]), read(f[1]);
	read(a), read(b);
	forn(i, 2, n) f[i] = (a * f[i - 2] + b * f[i - 1]) % mod;
	rep(i, n) read(x[i]);
	rep(i, q) read(l), read(r), update(l - 1, r - 1);
	rep(i, n) {
		if (i > 1) p[i] = (p[i] + a * p[i - 2]) % mod;
		if (i > 0) p[i] = (p[i] + b * p[i - 1]) % mod;
		x[i] = (x[i] + p[i]) % mod;
		cout << x[i] << " \n"[i == n - 1];
	}
	return 0;
}