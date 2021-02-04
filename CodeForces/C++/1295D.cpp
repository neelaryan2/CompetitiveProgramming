#include<bits/stdc++.h>
using namespace std;
void solve() {
	using ll = long long;
	ll a, m;
	cin >> a >> m;
	m /= __gcd(a, m);
	ll ans = m;
	for (ll i = 2; i * i <= m; i++) {
		if (m % i) continue;
		ans /= i; ans *= i - 1;
		while (m % i == 0) m /= i;
	}
	if (m != 1) ans /= m, ans *= m - 1;
	cout << ans << endl;
}
int main() {
	int t; cin >> t;
	while (t--) solve();
}