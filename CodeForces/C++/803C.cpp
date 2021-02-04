#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, k;
	cin >> n >> k;
	if (k > 1e6) {
		cout << -1 << endl;
		return 0;
	}
	ll tmp = (k * (k + 1)) / 2;
	if (tmp > n) {
		cout << -1 << endl;
		return 0;
	}
	set<ll> div;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i) continue;
		div.insert(i);
		div.insert(n / i);
	}
	auto it = div.lower_bound(n / tmp);
	if (*it != n / tmp) it--;
	ll gd = *it;
	for (int i = 1; i <= k - 1; i++)
		cout << gd*i << " ";
	cout << n + gd*(k - tmp) << endl;
}