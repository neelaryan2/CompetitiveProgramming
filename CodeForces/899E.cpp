#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
using pii = pair<pair<int, int>, int>;
using lit = list<pii>::iterator;
struct cmp {
	bool operator() (lit a, lit b) const {
		pii a1 = *a, b1 = *b;
		if (a1.se != b1.se) return a1.se > b1.se;
		else return a1.fi.se < b1.fi.se;
	}
};
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	a.emplace_back(0);
	list<pii> l;
	set<lit, cmp> s;
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		if (a[i + 1] != a[i]) {
			l.push_back(mp(mp(a[i], i), cnt));
			cnt = 1; s.insert(prev(l.end()));
		} else cnt++;
	}
	int ans = 0;
	while (!s.empty()) {
		lit p = *s.begin();
		lit p1 = prev(p), p2 = next(p);
		ans++; s.erase(p);
		if (p == l.begin() || p2 == l.end()) {
			l.erase(p);
			continue;
		}
		if ((*p1).fi.fi != (*p2).fi.fi) {
			l.erase(p);
			continue;
		}
		s.erase(p1); s.erase(p2);
		(*p1).se += (*p2).se;
		s.insert(p1);
		l.erase(p2);
		l.erase(p);
	}
	cout << ans << endl;
}