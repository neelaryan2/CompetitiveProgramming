#include<bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		int n, x, y;
		cin >> n >> x >> y;
		if (x + y <= n) cout << "1 " << x + y - 1 << endl;
		else cout << min(x + y + 1 - n, n) << " " << n << endl;
	}
}