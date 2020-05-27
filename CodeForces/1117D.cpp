/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
struct Matrix {
    using vi = vector<int>;
    int n, m, mod = 1e9 + 7;
    vector<vi> M;
    Matrix(int n1, int m1) {
        n = n1, m = m1;
        M.assign(n, vi(m, 0));
    }
    Matrix operator*(const Matrix& B) {
        assert(B.n == m);
        Matrix C = Matrix(n, B.m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < B.m; j++)
                for (int k = 0; k < m; k++)
                    C.M[i][j] = (C.M[i][j] + 1LL * M[i][k] * B.M[k][j]) % mod;
        return C;
    }
    Matrix operator*(const int& k) {
        Matrix C = *this;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                C.M[i][j] = (C.M[i][j] * k) % mod;
        return C;
    }
    Matrix operator+(const Matrix& B) {
        assert(B.n == n && B.m == m);
        Matrix C = Matrix(n, m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                C.M[i][j] = (M[i][j] + B.M[i][j]) % mod;
        return C;
    }
    Matrix operator-(const Matrix& B) {
        assert(B.n == n && B.m == m);
        Matrix C = Matrix(n, m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                C.M[i][j] = (M[i][j] - B.M[i][j]) % mod;
        return C;
    }
    Matrix exp(ll k) {
        assert(m == n);
        Matrix C = Matrix(n, n), A = *this;
        for (int i = 0; i < n; i++) C.M[i][i]++;
        while (k) {
            if (k & 1) C = C * A;
            A = A * A, k >>= 1;
        }
        return C;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    Matrix A = Matrix(m, m);
    for (int i = 1; i < m; i++)
        A.M[i][i - 1] = 1;
    A.M[0][0] = A.M[0][m - 1] = 1;
    A = A.exp(n);
    int ans = A.M[0][0];
    cout << ans << '\n';
}
