#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
int col = 1;
int a[maxn], ans[maxn];
int solve() {
	int n; cin >> n;
	int cnt = 0, last = -1;

	for (int i = 0; i < n; i++)
		cin >> a[i], ans[i] = 1;

	for (int i = 0; i < n; i++)
		if (a[i] == a[(i + 1) % n])
			cnt++, last = i;
	if (cnt == n) {	col = 1; return n; }
	if (n % 2 == 0) {
		col = 2;
		for (int i = 1; i < n; i += 2)
			ans[i] = 2;
		return n;
	}
	if (cnt == 0) {
		col = 3;
		for (int i = 1; i < n; i += 2)
			ans[i] = 2;
		ans[n - 1] = 3;
		return n;
	}
	col = 2;
	for (int i = last; i >= 0; i -= 2)
		ans[i] = 2;
	if (last + 1 == n) ans[0] = 2;
	for (int i = last + 1; i < n; i += 2)
		ans[i] = 2;
	return n;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		int n = solve();
		cout << col << endl;
		for (int i = 0; i < n; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
}