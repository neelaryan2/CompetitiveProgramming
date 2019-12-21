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
#define br() cout << endl

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
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-')f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}
const int N = 200005;
const int mod = 998244353;

vector<int> BIT(N, 0);
void add(int i, int x) {
	for (; i < N; i += i & (-i)) BIT[i] += x;
}
int get(int i) {
	int sum = 0;
	for (; i > 0; i -= i & (-i)) sum += BIT[i];
	return sum;
}
struct cmp {
	bool operator() (const pair<pi, int>& a, const pair<pi, int>& b) const {
		if (a.fi.se != b.fi.se) return a.fi.se < b.fi.se;
		else if (a.fi.fi != b.fi.fi) return a.fi.fi > b.fi.fi;
		else return a.se < b.se;
	}
};
vector<pair<pi, int>> seg;
set<pair<pi, int>, cmp> curr;
vi ans;
vector<bool> used(N, false);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n = read(), k = read(), l, r;
	rep(i, n) {
		l = read(); r = read();
		seg.pb(mp(mp(l, r), i));
		add(l, 1); add(r + 1, -1);
	}
	sort(all(seg));
	int ind = 0;
	forn(i, 1, N) {
		while (seg[ind].fi.fi <= i && i <= seg[ind].fi.se && ind < n)
			curr.ins(seg[ind]), ind++;
		while (get(i) > k) {
			auto it = curr.rbegin();
			l = (*it).fi.fi; r = (*it).fi.se;
			add(l, -1); add(r + 1, 1);
			ans.pb((*it).se + 1);
			curr.erase(prev(curr.end()));
		}
	}
	cout << sz(ans) << endl;
	sort(all(ans));
	pv(ans);
	return 0;
}