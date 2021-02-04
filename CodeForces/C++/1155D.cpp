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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, x; cin >> n >> x;
	ll el, ans, state1, state2, state3;
	ans = state1 = state2 = state3 = 0;
	rep(j, n) {
		cin >> el;
		state1 = max(0LL, state1 + el);
		state2 = max(state1, state2 + el * x);
		state3 = max(state2, state3 + el);
		ans = max(ans, state3);
	}
	cout << ans << endl;
	return 0;
}
