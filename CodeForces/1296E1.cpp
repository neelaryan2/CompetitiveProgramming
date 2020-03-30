#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; cin >> n;
	string s; cin >> s;
	vector<int> st(n, -1);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (s[j] >= s[i]) continue;
			if (st[i] != -1 && st[j] != -1) {
				if (st[i] != st[j]) continue;
				cout << "NO" << endl;
				return 0;
			} else if (st[i] == -1 && st[j] == -1) {
				st[i] = 0; st[j] = 1;
			} else if (st[j] == -1)
				st[j] = 1 - st[i];
			else st[i] = 1 - st[j];
		}
	}
	cout << "YES" << endl;
	for (int i : st) cout << ((i == -1) ? 0 : i);
	cout << endl;
}