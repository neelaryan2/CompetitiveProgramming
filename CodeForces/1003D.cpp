#include<bits/stdc++.h>
using namespace std;

const int maxb = 32;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<int> cnt(maxb, 0);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		cnt[int(log2(a))]++;
	}
	for (int i = 0; i < q; i++) {
		int b, ans = 0, curr = 0; cin >> b;
		for (int i = maxb - 1; i >= 0; i--) {
			curr = (curr << 1) + ((b >> i) & 1);
			ans += min(curr, cnt[i]);
			curr -= min(curr, cnt[i]);
		}
		if (curr > 0) ans = -1;
		cout << ans << "\n";
	}
}