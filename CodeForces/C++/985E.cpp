#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define fi first
#define se second
const int inf = 1e9;

bool get(int l, int r, vector<int>& p) {
	if (l > r) return false;
	if (l == 0) return p[r] >= 1;
	return p[r] - p[l - 1] >= 1;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k, d;
	cin >> n >> k >> d;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	vector<int> dp(n + 1, 0), p(n + 1, 0);
	dp[0] = 1; p[0] = 1; int l = 0;
	for (int i = 0; i < n; i++) {
		while (l < i && a[l] < a[i] - d) l++;
		int r = i + 1 - k;
		// cout << l << " " << r << endl;
		dp[i + 1] = get(l, r, p);
		p[i + 1] = p[i] + dp[i + 1];
	}
	// for (int i : dp) cout << i << " "; cout << endl;
	// for (int i : p) cout << i << " "; cout << endl;
	puts(dp[n] ? "YES" : "NO");
}