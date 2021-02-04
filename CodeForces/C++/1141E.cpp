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
ll n, H;
vector<ll> pref;
ll get(ll h) {
	rep(i, n) if (h + pref[i] <= 0) return i + 1;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> H >> n;
	pref.resize(n);
	rep(i, n) cin >> pref[i]; ll mn = pref[0];
	rep(i, n - 1) pref[i + 1] += pref[i], mn = min(mn, pref[i + 1]);
	ll ans = get(H), tot = -pref[n - 1], k;
	if (ans != -1 || tot <= 0) goto fin;
	k = 1 + ((H + mn - 1) / tot);
	ans = n * k + get(H - k * tot);
fin:
	cout << ans << endl;
	return 0;
}