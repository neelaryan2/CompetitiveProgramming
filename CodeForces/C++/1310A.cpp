#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define fi first
#define se second

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	vector<pii> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].fi;
	for (int i = 0; i < n; i++)
		cin >> a[i].se;
	sort(a.begin(), a.end());
	multiset<int> t;
	int curr = -1;
	ll tot = 0, ans = 0;
	for (pii p : a) {
		while (!t.empty() && p.fi != curr) {
			tot += *t.begin();
			t.erase(t.begin());
			ans += tot; curr++;
		}
		curr = p.fi;
		t.insert(-p.se);
		tot += p.se;
	}
	while (!t.empty()) {
		tot += *t.begin();
		t.erase(t.begin());
		ans += tot;
	}
	cout << ans << endl;
}