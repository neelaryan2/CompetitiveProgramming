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
#define puts(s) fputs(s, stdout)

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

int main() {
	ll t, a, b; read(t);
	while (t--) {
		read(a), read(b);
		if (a > b) swap(a, b);
		ll diff = b - a, lo = 1, hi = diff, mid, ans;
		if (a == b) {ans = 0; goto fin;}
		while (lo < hi - 1) {
			mid = (hi + lo) / 2;
			if (diff < (mid * (mid + 1)) / 2) hi = mid;
			else lo = mid;
		}
		diff -= (lo * (lo + 1)) / 2;
		if (diff != 0) lo++, diff = lo - diff;
		while (diff % 2) lo++, diff -= lo;
		ans = lo;
fin:
		cout << ans << endl;
	}
	return 0;
}