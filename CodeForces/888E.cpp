#include <bits/stdc++.h>
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
	int n, mod;
	cin >> n >> mod;
	int m = n - n / 2; n /= 2;
	vector<ll> a(n), b(m);
	for (int i = 0; i < n + m; i++) {
		int e; cin >> e;
		if (i < n) a[i] = e;
		else b[i - n] = e;
	}
	vector<ll> dp1(1 << n, 0), dp2(1 << m, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (1 << n); j++)
			if ((j >> i) & 1) dp1[j] = (dp1[j] + a[i]) % mod;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < (1 << m); j++)
			if ((j >> i) & 1) dp2[j] = (dp2[j] + b[i]) % mod;
	}
	sort(dp2.begin(), dp2.end());
	ll mx = -1;
	for (int i = 0; i < (1 << n); i++) {
		int j = upper_bound(dp2.begin(), dp2.end(), mod - 1 - dp1[i]) - dp2.begin();
		if (j != 0) j--;
		mx = max(mx, dp2[j] + dp1[i]);
	}
	cout << mx << endl;
}