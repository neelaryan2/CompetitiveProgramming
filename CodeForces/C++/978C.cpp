#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	vector<ll> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	for (int i = 0; i < m; i++) {
		ll b; cin >> b;
		int lo = 0, hi = n + 1, mid;
		while (lo < hi - 1) {
			mid = lo + (hi - lo) / 2;
			if (a[mid] >= b) hi = mid;
			else lo = mid;
		}
		cout << lo + 1 << " " << b - a[lo] << endl;
	}
}