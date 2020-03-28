#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifdef LOCAL
	    freopen("in.txt", "r", stdin);
	    freopen("out.txt", "w", stdout);
	#endif
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0, mx = 0;
	sort(a, a + n);
	for (int& i : a) {
		if (mx < i - 1) i--;
		if (mx == i) i++;
		if (mx < i) ans++, mx = i;
	}
	cout << ans << endl;
}