#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, a, b) for (int i = a; i < b; i++)
#define rfor(i, b, a) for (int i = b; i > a; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define forv(i, v) for (auto i = v.begin(); i != v.end(); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
const int N = int(1e9);
vector<ll> pref;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	pref.resize(n);
	rep(i, n) cin >> pref[i];
	forn(i, 1, n) pref[i] += pref[i - 1];
	ll tot = pref[n - 1], temp = 0; pref[n - 1] = 1e18;
	sort(all(pref));
	rep(i, k - 1) temp += pref[i];
	cout << k*tot - temp << endl;
	return 0;
}