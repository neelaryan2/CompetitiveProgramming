#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;
using pii = pair<int, int>;
#define se second
#define fi first

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	set<pii> s;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		s.insert(make_pair(a, i));
	}
	ll ans = 0;
	while (1) {
		auto it = s.begin(); it++;
		ans += s.size();
		while (it != s.end() && it->se > s.begin()->se) {
			s.erase(s.begin());
			it = s.begin(); it++;
		}
		pii p = *s.begin();
		s.erase(s.begin());
		if (s.empty()) break;
		it = s.begin();
		p.fi = s.begin()->fi;
		it = s.lower_bound(p);
		while (it != s.end() && it->fi == p.fi)
			it = s.erase(it);
		if (s.empty()) break;
	}
	cout << ans << endl;
}