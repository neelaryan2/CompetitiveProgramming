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
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		a[i] = c - '0';
	}
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		a[i] = 2 * a[i] + c - '0';
	}
	vector<int> tot(4, 0), cnt(4, 0);
	for (int i : a) tot[i]++;
	int tmp = tot[1] + tot[3], sum = -1;
	for (int i = 0; i <= tot[1] + tot[2]; i++) {
		int a0 = n - i - tmp;
		int a3 = tmp - i;
		if (a0 < 0 || a3 < 0) continue;
		if (a0 % 2 || a3 % 2) continue;
		a0 /= 2; a3 /= 2;
		if (a0 > tot[0] || a3 > tot[3]) continue;
		cnt[0] = a0; cnt[3] = a3;
		sum = i; break;
	}
	if (sum == -1) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i <= sum; i++) {
		if (sum - i > tot[2]) continue;
		cnt[1] = i; cnt[2] = sum - i; break;
	}
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		int& t = cnt[a[i]];
		if (t == 0) continue;
		ans.emplace_back(i + 1); t--;
	}
	for (int i : ans) cout << i << " ";	cout << endl;
}