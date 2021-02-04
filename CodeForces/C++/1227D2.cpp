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
const int N = 1e9 + 7;
const int mod = 998244353;
vector<int> BIT(200005, 0), ans, b;
vector<pi> a;
vector<pair<pi, int>> q;
// point update on the original array
void add(int i, int x) {
	for (; i < BIT.size(); i += i & (-i)) BIT[i] += x;
}
// get sum from index 1 to index i from array
int get(int i) {
	int sum = 0;
	for (; i > 0; i -= i & (-i)) sum += BIT[i];
	return sum;
}
// equivalent to calculating lower_bound on prefix sums array
int bit_search(ll val) {  //using binary lifting
	ll sum = 0, pos = 0;
	for (int i = log2(BIT.size()); i >= 0; i--)
		if (pos + (1 << i) < BIT.size() && sum + BIT[pos + (1 << i)] < val)
			sum += BIT[pos + (1 << i)],	pos += (1 << i);
	return pos + 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n = read(), k, pos, m; b.pb(N);
	rep(i, n) b.pb(read());
	rep(i, n + 1) a.pb(mp(-b[i], i));
	m = read();
	rep(i, m) {
		k = read(), pos = read();
		q.pb(mp(mp(k, pos), i));
	}
	sort(all(a)); sort(all(q));
	int ind = 1; ans.rsz(m, -1);
	rep(i, m) {
		while (q[i].fi.fi >= ind) add(a[ind].se, 1), ind++;
		ans[q[i].se] = b[bit_search(q[i].fi.se)];
	}
	for (int x : ans) cout << x << endl;
	return 0;
}