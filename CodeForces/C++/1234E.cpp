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
ll n, m, previous, x, mx, mn, f0 = 0;
vector<ll> pref;
void update(int l, int r, int x) {
	if (l - 1 >= r) return;
	pref[l - 1] += x;
	pref[r] -= x;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> previous;
	pref.resize(n + 1);
	rep(i, n + 1) pref[i] = 0;
	rep(i, m - 1) {
		cin >> x;
		mx = max(x, previous); mn = min(x, previous);
		previous = x; f0 += mx - mn;
		if (mx == mn) continue;
		update(mn, mn, mn - 1);
		update(mx, mx, 2 * mn - mx);
		update(mn + 1, mx - 1, -1);
	}
	pref[0] += f0; rep(i, n - 1) pref[i + 1] += pref[i];
	rep(i, n) cout << pref[i] << " "; cout << endl;
	return 0;
}