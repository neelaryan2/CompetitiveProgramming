#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define eb emplace_back

const int maxe = 2e6 + 2;
const int off = 1e6;
vector<int> ans, s;
vector<bool> vis(maxe, false);
inline bool check(int v) {
	if (v > 0) {
		if (vis[v]) return true;
		else vis[v] = true;
	} else {
		if (!vis[-v]) return true;
		if (vis[-v + off]) return true;
		else vis[-v + off] = true;
	}
	return false;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, a; cin >> n;
	long long pref = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		pref += (long long) a;
		if (pref < 0) goto no;
		if (check(a)) goto no;
		s.eb(abs(a));
		if (pref == 0) {
			ans.eb(s.size());
			for (int t : s) {
				vis[t] = false;
				vis[t + off] = false;
			}
			s.clear();
		}
	}
	if (pref != 0 || accumulate(ans.begin(), ans.end(), 0) != n)
		goto no;
	cout << ans.size() << endl;
	for (int an : ans) cout << an << " ";
	cout << endl;
	return 0;
no:
	cout << "-1" << endl;
}