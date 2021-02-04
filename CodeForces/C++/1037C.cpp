#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, ans = 0;
	string a, b;
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) continue;
		ans++;
		if (i == n || a[i] == a[i + 1]) continue;
		if (a[i + 1] != b[i + 1]) i++;
	}
	cout << ans << endl;
}