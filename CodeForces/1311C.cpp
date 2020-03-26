#include<bits/stdc++.h>
using namespace std;

using ll = long long;
void solve() {
	int n, m;
	string s;
	cin >> n >> m >> s;
	vector<int> tot(n + 1, 0), cnt(26, 0);
	for (int i = 0; i < m; i++) {
		int p; cin >> p;
		tot[0]++; tot[p]--;
	}
	for (int i = 0; i < n; i++) {
		tot[i + 1] += tot[i];
		cnt[s[i] - 'a'] += tot[i] + 1;
	}
	for (int i = 0; i < 26; i++)
		cout << cnt[i] << " ";
	cout << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) solve();
}