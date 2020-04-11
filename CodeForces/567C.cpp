#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, k;
	cin >> n >> k;
	map<ll, ll> cnt, pp;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll a; cin >> a;
		if (a % k == 0) {
			ll b = a / k;
			if (b % k == 0)
				ans += pp[b];
			pp[a] += cnt[b];
		}
		cnt[a]++;
	}
	cout << ans << endl;
}