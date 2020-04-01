#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
#define vi vector<ll>
#define sz(v) int((v).size())
vector<vi> matmul(vector<vi> A, vector<vi> B) {
	int n = sz(A), m = sz(A[0]), p = sz(B[0]);
	assert(sz(B) == m);
	vector<vi> C(n, vi(p, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < p; j++)
			for (int k = 0; k < m; k++) {
				C[i][j] += (A[i][k] * B[k][j]) % mod;
				C[i][j] %= mod;
			}
	return C;
}
vector<vi> matexp(vector<vi> A, int k) {
	int n = A.size();
	assert(sz(A[0]) == n);
	vector<vi> C(n, vi(n, 0));
	for (int i = 0; i < n; i++) C[i][i]++;
	while (k) {
		if (k & 1) C = matmul(C, A);
		A = matmul(A, A); k >>= 1;
	}
	return C;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vi> A = {{1, 1}, {1, 0}};
	ll ans = matexp(A, n)[0][0];
	ans = (ans + matexp(A, m)[0][0]) % mod;
	ans = (2 * ans - 2) % mod;
	if (ans < 0) ans += mod;
	cout << ans << endl;
}
