#include<bits/stdc++.h>
using namespace std;

const int maxn = 101;
int p[maxn], dp[maxn][maxn][2];

int calc(int pos, int odds, int evens, int nxt) {
	if (odds < 0 || evens < 0 || pos < 0) return 1e9;
	int& ans = dp[pos][evens][nxt];
	if (pos == 0 && p[pos] == -1) return ans = (evens == nxt);
	if (pos == 0 && p[pos] != -1) return ans = (p[pos] != nxt);
	if (ans != -1) return ans;
	if (p[pos] != -1) {
		ans = calc(pos - 1, odds, evens, p[pos]) + (p[pos] != nxt);
		return ans;
	}
	ans = calc(pos - 1, odds - 1, evens, 1) + (1 != nxt);
	ans = min(ans, calc(pos - 1, odds, evens - 1, 0) + (0 != nxt));
	return ans;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; cin >> n;
	memset(p, -1, sizeof(p));
	memset(dp, -1, sizeof(dp));
	int even = n / 2, odd = n - even;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (!a) continue;
		p[i] = a & 1;
		if (a & 1) odd--; else even--;
	}
	int ans = min(calc(n - 1, odd, even, 1), calc(n - 1, odd, even, 0));
	cout << ans << "\n";
}