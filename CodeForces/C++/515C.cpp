#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define fi first
#define se second
#define eb emplace_back

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		int num = c - '0';
		if (num == 0) continue;
		else if (num == 1) continue;
		else if (num == 2) ans.eb(2);
		else if (num == 3) ans.eb(3);
		else if (num == 4) {
			ans.eb(2); ans.eb(2);
			ans.eb(3);
		}
		else if (num == 5) ans.eb(5);
		else if (num == 6) {
			ans.eb(5); ans.eb(3);
		}
		else if (num == 7) ans.eb(7);
		else if (num == 8) {
			ans.eb(7); ans.eb(2);
			ans.eb(2); ans.eb(2);
		}
		else if (num == 9) {
			ans.eb(7); ans.eb(3);
			ans.eb(3); ans.eb(2);
		}
	}
	sort(ans.begin(), ans.end(), greater<int>());
	for (int i : ans) cout << i; cout << endl;
}