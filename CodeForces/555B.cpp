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
vi ans;
vpl isl;
vector<pair<pl, int>> seg;
set<pair<ll, int>> b;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n = read(), m = read();
	ans.rsz(n - 1, -1);
	rep(i, n) isl.pb(mp(read(), read()));
	rep(i, m) b.ins(mp(read(), i));
	rep(i, n - 1) seg.pb(mp(mp(isl[i + 1].fi - isl[i].se, isl[i + 1].se - isl[i].fi), i));
	sort(all(seg));
	rep(i, n - 1) {
		if (b.empty()) goto no;
		auto it = b.lb(mp(seg[i].fi.se, -1));
		if (it == b.end() || seg[i].fi.fi < (it->fi)) goto no;
		ans[seg[i].se] = (it->se) + 1;
		b.erase(it);
	}
	cout << "Yes" << endl;
	pv(ans); return 0;
no:
	cout << "No" << endl;
	return 0;
}