#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define fi first
#define se second
#define eb emplace_back

#define vi vector<ll>
#define sz(v) int((v).size())

const int mod = 1e9 + 7;
vector<vi> matmul(vector<vi> A, vector<vi> B) {
	int n = sz(A), m = sz(A[0]), p = sz(B[0]);
	assert(sz(B) == m);
	vector<vi> C(n, vi(p, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < p; j++)
			for (int k = 0; k < m; k++) {
				C[i][j] += (A[i][k] * B[k][j]) % mod;
				C[i][j] = C[i][j] % mod;
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
	int n; cin >> n;
	vector<vi> v = {{0, 3}, {1, 2}};
	v = matexp(v, n);
	cout << v[0][0] << endl;
}