#include<bits/stdc++.h>
using namespace std;
vector<int> maxdp(1e5 + 5, 0);
void solve() {
	int n; cin >> n;
	vector<int> a(n);
	set<int> s;
	for (int j = 0; j < n; j++) {
		cin >> a[j];
		for (int i = 2; i * i <= a[j]; i++) {
			if (a[j] % i == 0) {
				s.insert(i);
				break;
			}
		}
	}
	cout << s.size() << endl;
	vector<int> p;
	p.assign(s.begin(), s.end());
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < s.size(); j++) {
			if (a[i] % p[j] == 0) {
				cout << j + 1 << " ";
				break;
			}
		}
	}
	cout << endl;
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
	while (t--) solve();
}