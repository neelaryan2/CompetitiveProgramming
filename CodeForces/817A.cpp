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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x1, y1, x2, y2, x, y;
	read(x1); read(y1); read(x2); read(y2);
	read(x); read(y);
	x1 = abs(x2 - x1), y1 = abs(y2 - y1);
	if (x1 % x != 0 || y1 % y != 0) goto no;
	x1 /= x; y1 /= y;
	if (x1 % 2 != y1 % 2) goto no;
	puts("YES");
	return 0;
no:
	puts("NO");
}