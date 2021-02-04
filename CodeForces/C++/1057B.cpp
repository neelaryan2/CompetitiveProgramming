#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	for (int i = 0; i < n; i++)
		for (int len = 1; len + i <= n; len++)
			if (a[i + len] - a[i] > 100 * len)
				ans = max(ans, len);
	cout << ans << endl;
}