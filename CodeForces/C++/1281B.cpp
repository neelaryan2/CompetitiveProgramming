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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests, ind1, ind2; cin >> tests;
	string s, t, sorted; char mn;
	while (tests--) {
		cin >> s >> t; sorted = s;
		sort(all(sorted)); ind1 = -1;
		rep(i, sz(s)) if (sorted[i] != s[i]) {ind1 = i; mn = sorted[i]; break;}
		if(ind1==-1) goto fin;
		forn(i, ind1 + 1, sz(s)) if (s[i] == mn) ind2 = i;
		swap(s[ind1], s[ind2]);
fin:
		if (s >= t) {cout << "---" << endl; continue;}
		cout << s << endl;
	}
	return 0;
}