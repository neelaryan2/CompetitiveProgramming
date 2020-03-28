#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void disp(vector<int> a) {
	for (int i : a)
		cout << i;
	cout << endl;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int i = 0 ; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	int ans;
	if (k == 0) {
		if (a[0] == 1) ans = -1;
		else ans = a[0] - 1;
		cout << ans << endl;
		return 0;
	}
	ans = a[k - 1];
	if (k != n && a[k] <= ans) ans = -1;
	cout << ans << endl;
}