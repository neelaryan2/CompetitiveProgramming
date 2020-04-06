#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
	ll d, m;
	cin >> d >> m;
	if (d == 1) return 1 % m;
	int b = log2(d);
	vector<ll> calc(b + 1, 1);
	for (ll i = 1, pw = 2; i <= b; i++, pw <<= 1) {
		if (i == b) pw = d - pw + 1;
		calc[i] = (pw * calc[i - 1]) % m;
		calc[i] = (calc[i] + pw + calc[i - 1]) % m;
	}
	return calc.back();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) cout << solve() << endl;;
}