#include<bits/stdc++.h>
using namespace std;

int main() {
	#ifdef LOCAL
	    freopen("in.txt", "r", stdin);
	    freopen("out.txt", "w", stdout);
	#endif
	int n; cin >> n;
	vector<bool> a(n), ans(n, true);
	bool an = 0;
	for (int i = 0; i < n; i++) {
		char c;	cin >> c;
		a[i] = (c == '1');
		an = an || a[i];
	}
	if (!an) {
		cout << n << endl;
		return 0;
	}
	ans[0] = false;
	for (int d = 1; d < n; d++) {
		if (n % d) {
			ans[d] = ans[__gcd(n, d)];
			continue;
		}
		for (int i = 0; i < d; i++) {
			bool val = 0;
			for (int j = i; j < n; j += d)
				val ^= a[j];
			ans[d] = ans[d] && !val;
		}
	}
	int sz = 0;
	for (bool b : ans) sz += b;
	cout << sz << endl;
}