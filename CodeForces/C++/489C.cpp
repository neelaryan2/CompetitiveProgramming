#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int m, s;
	cin >> m >> s;
	if (s == 0 && m == 1) {
		cout << "0 0\n";
		return 0;
	}
	if (s == 0 || s > 9 * m) {
		cout << "-1 -1\n";
		return 0;
	}
	vector<int> mn(m, 9), mx(m, 9);
	int tmp = s;
	for (int i = 0; i < m; i++) {
		int t = min(tmp, mx[i]);
		mx[i] = t; tmp -= t;
	}
	tmp = s - 1; mn[0] = 1;
	for (int i = m - 1; i > 0; i--) {
		int t = min(tmp, mn[i]);
		mn[i] = t; tmp -= t;
	}
	if (tmp != 0) mn[0] = tmp + 1;
	for (int i : mn) cout << i; cout << " ";
	for (int i : mx) cout << i; cout << endl;
}