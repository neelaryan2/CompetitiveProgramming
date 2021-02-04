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
	cout << endl;
}
inline ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-')f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}
const int N = 1e9 + 7;
const int mod = 998244353;

vl sa, sb, fa, fb, a, b;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n = read();
	sa.rsz(n); sb.rsz(n); fa.rsz(n); fb.rsz(n);
	rep(i, n) a.pb(read());
	rep(i, n) b.pb(read());
	sa[n - 1] = a[n - 1]; fa[n - 1] = (n - 1) * a[n - 1];
	sb[n - 1] = b[n - 1]; fb[n - 1] = (n - 1) * b[n - 1];
	repr(i, n - 1) sa[i] = sa[i + 1] + a[i], fa[i] = fa[i + 1] + a[i] * i;
	repr(i, n - 1) sb[i] = sb[i + 1] + b[i], fb[i] = fb[i + 1] + b[i] * i;
	ll cur = 0, ans = 0;
	rep(i, n) {
		if (i & 1) {
			ans = max(ans, cur + fb[i] + i * sb[i] + (2 * n + i - 1) * sa[i] - fa[i]);
			cur += (2 * i) * (a[i] + b[i]) + a[i];
		} else {
			ans = max(ans, cur + fa[i] + i * sa[i] + (2 * n + i - 1) * sb[i] - fb[i]);
			cur += (2 * i) * (a[i] + b[i]) + b[i];
		}
	}
	cout << ans << endl;
	return 0;
}