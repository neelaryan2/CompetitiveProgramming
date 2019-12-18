#include<bits/stdc++.h>
using namespace std;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define rfor(i, b, a) for (int i = b; i > a; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define forv(i, v) for (auto i : v)

#define all(v) v.begin(), v.end()
#define sz(v) int(v.size())
#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(min(a, b), min(c, d))

#define popcnt __builtin_popcount
#define popcntll __builtin_popcountll
#define par __builtin_parity
#define parll __builtin_parityll
#define ctz __builtin_ctz
#define ctzll __builtin_ctzll
#define gcd __gcd

#define ll long long
#define ull unsigned long long int
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define pii pair<int, int>
#define vi vector<int>
#define endl "\n"

#define Set(n, i) n = n | (1LL << i)
#define Reset(n, i) n = n & ~(1LL << i)
#define Test(n, i) (n >> i & 1LL)

const int N = 1e9 + 1;
ll path(ll n, ll k) {
	for (ll i = 1; i <= k && n; i = i * 2 + 1) k -= i, n--;
	return n;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	ll n, k, ans, i;
	while (t--) {
		cin >> n >> k; ans = path(n, k);
		if (n == 2 && k == 3) goto no;
		if (n > 60) goto yes;
		for (i = 1; n--; i *= 4) k -= i;
		if (k > 0) goto no;
yes:
		cout << "YES " << ans << endl;
		continue;
no:
		cout << "NO" << endl;
	}
	return 0;
}