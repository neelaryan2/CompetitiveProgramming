#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int solve() {
	string s; cin >> s; s.push_back('R');
	int n = s.size(), prev = 0, ans = -1;
	for (int i = 0; i <= n; i++) {
		if (s[i] != 'R') continue;
		ans = max(ans, i + 1 - prev);
		prev = i + 1;
	}
	return ans;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; cin >> n;
	while (n--) cout << solve() << endl;
}