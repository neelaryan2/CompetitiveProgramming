#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define fi first
#define se second
const int inf = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; cin >> n;
	string st; cin >> st;
	set<pii> s;
	vector<int> ans;
	for (char c : st) {
		if (s.empty() || s.begin()->fi > c)
			s.insert(make_pair(c, s.size()));
		auto it = s.upper_bound(make_pair(c, inf));
		it--; ans.emplace_back(it->se);
		s.erase(it); s.insert(make_pair(c, ans.back()));
	}
	cout << s.size() << endl;
	for (int i : ans) cout << i + 1 << " ";
	cout << endl;
}