#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
	int n, k;
	cin >> n >> k;
	vector<ll> a(n), p(n + 1, 0);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
		p[i + 1] = p[i] + a[i];
	ll left, right, ans = 1e18;
	for (int i = 0, j = 0; i < n; i = j) {
		while (j < n && a[i] == a[j]) j++;
		if (j - i >= k) {ans = 0; break;}
		left = i * a[i] - p[i] + p[0];
		right = p[n] - p[j] - (n - j) * a[i];
		if (j >= k) ans = min(ans, left + k - j);
		if (i <= n - k) ans = min(ans, right - n + k + i);
		ans = min(ans, left + right - n + k);
	}
	cout << ans << endl;
}