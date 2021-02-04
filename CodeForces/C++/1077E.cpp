#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<int> hi(n + 1);
	map<int, int> cnt;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		cnt[a]++;
	}
	for (pii p : cnt)
		hi[p.second]++;
	for (int i = n - 2; i >= 0; i--)
		hi[i] += hi[i + 1];
	int ans = -1;
	for (int i = 1; i <= n; i++) {
		int cnts = 0, sum = 0;
		for (int j = i; j > 0; j >>= 1) {
			cnts++;
			if (cnts > hi[j]) break;
			sum += j;
			if (j % 2) break;
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
}