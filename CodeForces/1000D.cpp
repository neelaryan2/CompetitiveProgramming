#include<bits/stdc++.h>
using namespace std;
const int kMod = 998244353;
struct ModInt {
	long long n;
	ModInt(long long n = 0) : n(n % kMod) {}
	ModInt operator+(const ModInt& oth) { return n + oth.n; }
	ModInt operator-(const ModInt& oth) { return n - oth.n; }
	ModInt operator*(const ModInt& oth) { return n * oth.n; }
	long long get() { return n < 0 ? n + kMod : n; }
};
ModInt lgpow(ModInt b, int e = -1) {
	if (b.get() == 0) return 0;
	ModInt r; e = e % (kMod - 1);
	if (e < 0) e += kMod - 1;
	for (r = 1; e; e >>= 1, b = b * b)
		if (e & 1) r = r * b;
	return r;
}
vector<ModInt> fact, invfact;
void factorials(int n) {
	fact.resize(n + 1, 1);
	invfact.resize(n + 1, 1);
	for (int i = 1; i <= n; ++i)
		fact[i] = fact[i - 1] * i;
	invfact[n] = lgpow(fact[n]);
	for (int i = n - 1; i >= 1; --i)
		invfact[i] = invfact[i + 1] * (i + 1);
}
ModInt choose(int n, int k) {
	if (k < 0 || k > n) return 0;
	return fact[n] * invfact[k] * invfact[n - k];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	if (n == 1) {cout << 0 << endl; return 0;}
	factorials(n);
	int arr[n];
	ModInt dp[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	dp[n - 1] = 0;
	for (int i = n - 2; i >= 0; i--) {
		int c = arr[i]; ModInt res; dp[i] = dp[i + 1];
		if (c <= 0 || c >= n - i) continue;
		for (int j = i + c; j < n; j++) {
			res = (j + 1 >= n) ? 0 : dp[j + 1];
			res = res + 1;
			res = res * choose(j - i - 1, c - 1);
			dp[i] = dp[i] + res;
		}
	}
	cout << dp[0].get() << endl;
}