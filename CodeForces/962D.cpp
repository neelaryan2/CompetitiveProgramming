#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pi;
#define fi first
#define se second
#define eb emplace_back
#define mp make_pair

vector<ll> a, ans;
set<pi> s;
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int b; cin >> b;
		a.eb(b);
		s.insert(mp(b, i));
	}
	while (1) {
		auto it1 = s.begin();
		if (s.size() == 1) {
			a[it1->se] = it1->fi;
			s.erase(it1);
			break;
		}
		auto it2 = next(s.begin());
		if (it1->fi == it2->fi) {
			s.insert(mp(2 * it2->fi, it2->se));
			a[it1->se] = -1;
			s.erase(it1); s.erase(it2);
		} else {
			a[it1->se] = it1->fi;
			s.erase(it1);
		}
	}
	for (ll b : a) if (b != -1) ans.eb(b);
	cout << ans.size() << "\n";
	for (ll b : ans) cout << b << " ";
	cout << "\n";
}