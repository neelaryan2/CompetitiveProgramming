#include<bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; cin >> n;
	string s; cin >> s;
	int m; cin >> m;
	vector<bool> used(26, false), ans(26, true);
	for (char c : s) {
		if (c == '*') continue;
		used[c - 'a'] = true;
		ans[c - 'a'] = false;
	}
	for (int i = 0; i < m; i++) {
		string t; cin >> t;
		bool take = true;
		for (int i = 0; i < n; i++) {
			if (s[i] != '*') continue;
			if (!used[t[i] - 'a']) continue;
			take = false; break;
		}
		for (int i = 0; i < n; i++) {
			if (s[i] == '*') continue;
			if (t[i] == s[i]) continue;
			take = false; break;
		}
		if (!take) continue;
		for (int i = 0; i < 26; i++) {
			ans[i] = ans[i] && (t.find(char(i + 'a')) != string::npos);
		}
	}
	cout << accumulate(ans.begin(), ans.end(), 0) << endl;
}