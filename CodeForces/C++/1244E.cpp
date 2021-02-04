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
#define pp pair<int, int>
#define vi vector<int>
const int N = int(1e9);
ll n, k;
vector<ll> a, pref;
bool possible(ll diff) {
	ll best = 1e17, moves;
	rep(i, n) {
		int  j = ub(all(a), a[i] + diff) - a.begin();
		int  k = lb(all(a), a[i]) - a.begin();
		moves = k * a[i];
		if (k != 0) moves -= pref[k - 1];
		moves += pref[n - 1] - pref[j - 1]  - (n - j) * (a[i] + diff);
		best = min(best, moves);
	}
	rep(i, n) {
		int  j = ub(all(a), a[i]) - a.begin();
		int  k = lb(all(a), a[i] - diff) - a.begin();
		moves = k * (a[i] - diff);
		if (k != 0) moves -= pref[k - 1];
		moves += pref[n - 1] - pref[j - 1]  - (n - j) * a[i];
		best = min(best, moves);
	}
	return best <= k;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	a.resize(n); pref.resize(n);
	rep(i, n) cin >> a[i];
	sort(all(a)); pref[0] = a[0];
	rep(i, n - 1) pref[i + 1] = pref[i] + a[i + 1];
	ll lo = -1, hi = a[n - 1] - a[0] + 5, mid;
	while (lo < hi - 1) {
		mid = (lo + hi) / 2;
		if (possible(mid)) hi = mid;
		else lo = mid;
	}
	cout << hi << endl;
	return 0;
}