/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define sz(v) int((v).size())
const int mod = 1e9 + 7;
vector<vi> matmul(vector<vi> A, vector<vi> B) {
    int n = sz(A), m = sz(A[0]), p = sz(B[0]);
    assert(sz(B) == m);
    vector<vi> C(n, vi(p, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            for (int k = 0; k < m; k++) {
                C[i][j] += (1LL * A[i][k] * B[k][j]) % mod;
                if (C[i][j] >= mod) C[i][j] -= mod;
            }
    return C;
}
vector<vi> matexp(vector<vi> A, ll k) {
    int n = A.size();
    assert(sz(A[0]) == n);
    vector<vi> C(n, vi(n, 0));
    for (int i = 0; i < n; i++) C[i][i]++;
    while (k) {
        if (k & 1) C = matmul(C, A);
        A = matmul(A, A);
        k >>= 1;
    }
    return C;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vi> M(m, vi(m, 1));
    for (int i = 0; i < k; i++) {
        char c1, c2;
        cin >> c1 >> c2;
        int i1, i2;
        if (c1 >= 'a')
            i1 = c1 - 'a';
        else if (c1 >= 'A')
            i1 = c1 - 'A' + 26;
        if (c2 >= 'a')
            i2 = c2 - 'a';
        else if (c2 >= 'A')
            i2 = c2 - 'A' + 26;
        M[i1][i2] = 0;
    }
    M = matexp(M, n - 1);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            ans = (ans + M[i][j]) % mod;
        }
    }
    cout << ans << '\n';
}
