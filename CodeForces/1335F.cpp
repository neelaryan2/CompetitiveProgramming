#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n, m, lognm = 0;
	cin >> n >> m;
	int nm = n * m;
	for (; (1 << lognm) < nm; lognm++);
	int cnt[nm], nxt[nm][lognm];
	bool fav[nm];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			fav[i * m + j] = (c == '0');
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			int v = i * m + j;
			cnt[v] = 0;
			if (c == 'U') v -= m;
			if (c == 'D') v += m;
			if (c == 'L') v--;
			if (c == 'R') v++;
			nxt[i * m + j][0] = v;
		}
	}
	for (int j = 1; j < lognm; j++)
		for (int i = 0; i < nm; i++)
			nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];

	for (int i = 0; i < nm; i++) {
		int j = i;
		for (int k = lognm - 1; k >= 0; k--)
			if (nm >= (1 << k))
				j = nxt[j][k];
		if (fav[i]) cnt[j] = 1;
		else if (!cnt[j]) cnt[j] = -1;
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < nm; i++) {
		if (!cnt[i]) continue;
		if (cnt[i] == 1) ans2++; ans1++;
	}
	cout << ans1 << " " << ans2 << endl;

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) solve();
}