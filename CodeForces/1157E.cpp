#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using vs = vector<string>;
#define fi first
#define se second
const ll mod = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<int> a(n);
	multiset<int> b;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		int bx; cin >> bx;
		b.insert(bx);
	}
	for (int i = 0; i < n; i++) {
		auto it = b.lower_bound(n - a[i]);
		if (it == b.end()) it = b.begin();
		a[i] = (a[i] + *it) % n;
		b.erase(it);
	}
	for (int i : a) cout << i << " "; cout << endl;
}