#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, a, b) for (int i = a; i < b; i++)
#define rfor(i, b, a) for (int i = b; i > a; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n - 1; i >=0; i--)
#define forv(i, v) for (auto i = v.begin(); i != v.end(); i++)
#define all(v) v.begin(), v.end()
#define sz(v) int(v.size())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
ll n, k;
// ll num_bits(ll n) {
// 	ll ans = 0;
// 	while (n) n /= 2, ans++;
// 	return ans;
// }
// ll power(ll x, ll k) {
// 	ll ans = x;
// 	if (!k) return 1;
// 	while (k != 1) {
// 		if (k % 2) ans *= x, k--;
// 		else ans = ans * ans, k /= 2;
// 	}
// 	return ans;
// }
// ll left(ll x, ll k) {
// 	ll ans = x;
// 	if (k >= 0) ans *= power(2, k);
// 	if (k < 0) while (k) ans /= 2, k++;
// 	return ans;
// }
ll get(ll x) {
	ll diff = (ll)log2(n / x);
	ll cnt = (1LL << diff) - 1;
	if (((ll)n >> diff) > x) cnt += (1LL << diff);
	if (((ll)n >> diff) == x) cnt += n - (ll)(x << diff) + 1;
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	ll lo = 0, hi = 1 + n / 2, mid, ans = 0;
	while (lo < hi - 1) {
		mid = (lo + hi) / 2;
		ll cnt = get(2 * mid);
		cnt += get(2 * mid + 1);
		if (cnt >= k || cnt < 0) lo = mid;
		else hi = mid;
	}
	ans = 2 * lo;
	lo = 0, hi = 1 + n / 2;
	while (lo < hi - 1) {
		mid = (lo + hi) / 2;
		ll cnt = get(2 * mid + 1);
		if (cnt >= k || cnt < 0) lo = mid;
		else hi = mid;
	}
	ans = max(2 * lo + 1, ans);
	cout << ans << endl;
	return 0;
}