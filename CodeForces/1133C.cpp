#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int k = 5;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int j = upper_bound(a.begin() + i, a.end(), a[i] + k) - a.begin();
		ans = max(ans, j - i);
	}
	cout << ans << endl;
}