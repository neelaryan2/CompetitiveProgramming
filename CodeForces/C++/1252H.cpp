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
const int N = int(1e5) + 5;
vector<pair<ll, ll>> lw;
vector<ll> w;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, x, y;
	ll ans = 0;
	cin >> n;
	lw.resize(n); w.resize(n);
	rep(i, n) {
		cin >> x >> y;
		if (x > y) lw[i] = {y, x};
		else lw[i] = {x, y};
	}
	sort(all(lw));
	string str = ".0";
	w[n - 1] = 0;
	rfor(i, n - 2, -1)
		w[i] = max(w[i + 1], lw[i + 1].se);
	forn(i, 0, n - 1)
		ans = max(ans, lw[i].fi * min(lw[i].se, w[i]));
	ll temp = 0;
	for (auto p : lw)
		temp = max(temp, p.fi * p.se);
	if(temp%2 && temp/2>=ans){
		str=".5";
	}
	ans = max(ans, temp/2);
	cout << ans << str << endl;
	return 0;
}