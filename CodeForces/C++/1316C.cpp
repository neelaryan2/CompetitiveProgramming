#include<bits/stdc++.h>
using namespace std;

int main() {
	#ifdef LOCAL
	    freopen("in.txt", "r", stdin);
	    freopen("out.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, p;
	cin >> n >> m >> p;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (a[i] % p) {
			ans += i;
			break;
		}
	for (int i = 0; i < m; i++)
		if (b[i] % p) {
			ans += i;
			break;
		}
	cout << ans << endl;
}