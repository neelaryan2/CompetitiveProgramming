#include<bits/stdc++.h>
using namespace std;
vector<int> s, a, b;
using ll = long long;
void solve() {
	int n; cin >> n;
	s.resize(n); b.resize(n); a.resize(n);
	for (int i = 0; i < n; i++) {
		char c; cin >> c; a[i] = 0;
		s[i] = b[i] = c - '0';
	}
	for (int i = 0; i < n; i++) {
		b[i] = s[i] / 2;
		a[i] = s[i] - b[i];
		if (s[i] == 1) break;
	}
	for (int i : a) cout << i; cout << endl;
	for (int i : b) cout << i; cout << endl;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) solve();
}