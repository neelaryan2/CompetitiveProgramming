#include<bits/stdc++.h>
using namespace std;
const int kMod = 1e9 + 7;
struct ModInt {
	long long n;
	ModInt(long long n = 0) : n(n % kMod) {}
	ModInt operator+(const ModInt& oth) { return n + oth.n; }
	ModInt operator-(const ModInt& oth) { return n - oth.n; }
	ModInt operator*(const ModInt& oth) { return n * oth.n; }
	long long get() { return n < 0 ? n + kMod : n; }
};
#define vi vector<ModInt>
int main() {
	int n, m;
	cin >> n >> m;
	int mn = 0, sum = 0;
	for (int i = 0; i < m; i++) {
		char c; cin >> c;
		sum += (c == '(') ? 1 : -1;
		mn = min(mn, sum);
	}
	int k = n - m;
	vector<vi> dp(k + 1, vi(k + 1, 0));
	dp[0][0] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= k; j++) {
			if (j > 0) dp[i][j] = dp[i][j] + dp[i - 1][j - 1];
			if (j < k) dp[i][j] = dp[i][j] + dp[i - 1][j + 1];
		}
	}
	ModInt ans = 0;
	for (int i = 0; i <= k; i++)
		for (int j = 0; j <= k; j++)
			if (j + mn >= 0 && j + sum <= k)
				ans = ans + dp[i][j] * dp[k - i][j + sum];
	cout << ans.get() << endl;
}