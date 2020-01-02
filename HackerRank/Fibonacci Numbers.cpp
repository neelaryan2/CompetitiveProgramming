#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define sz(v) int((v).size())
vector<vi> matmul(vector<vi> A, vector<vi> B) {
	int n = sz(A), m = sz(A[0]), p = sz(B[0]);
	assert(sz(B) == m);
	vector<vi> C(n, vi(p, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < p; j++)
			for (int k = 0; k < m; k++)
				C[i][j] += A[i][k] * B[k][j];
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
const vector<vi> F = {{1, 1}, {1, 0}};
const vector<vi> f = {{1}, {0}};
int main() {
	int n; cin >> n;
	cout << matmul(matexp(F, n - 1), f)[0][0] << endl;
}