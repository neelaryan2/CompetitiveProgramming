#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve() {
	string s, t;
	cin >> s >> t;
	vector<set<int>> pos(26);
	for (int i = 0; i < s.size(); i++)
		pos[s[i] - 'a'].insert(i);
	int ans = 1, ind = -1;
	for (int i = 0; i < t.size(); i++) {
		int c = t[i] - 'a';
		auto it = pos[c].upper_bound(ind);
		if (it == pos[c].end() && ind == -1)
			return -1;
		if (it != pos[c].end()) ind = *it;
		else ind = -1, ans++, i--;
	}
	return ans;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) cout << solve() << endl;
}