#include <bits/stdc++.h>

using namespace std;

// Complete the stepPerms function below.
#define vi vector<long long>
#define sz(v) int((v).size())
const long long mod = 1e10 + 7;
vector<vi> matmul(vector<vi> A, vector<vi> B) {
	int n = sz(A), m = sz(A[0]), p = sz(B[0]);
	assert(sz(B) == m);
	vector<vi> C(n, vi(p, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < p; j++)
			for (int k = 0; k < m; k++)
				C[i][j] = (C[i][j] + (1LL * A[i][k] * B[k][j]) % mod) % mod;;
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
const vector<vi> F = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
const vector<vi> f = {{2}, {1}, {1}};
int stepPerms(int n) {
	return matmul(matexp(F, n - 1), f)[1][0];
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int s;
	cin >> s;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int s_itr = 0; s_itr < s; s_itr++) {
		int n;
		cin >> n;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		int res = stepPerms(n);

		fout << res << "\n";
	}

	fout.close();

	return 0;
}
