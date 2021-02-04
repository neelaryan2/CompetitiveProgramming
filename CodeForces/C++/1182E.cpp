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
#define sz(v) int((v).size())

int mod = 1e9 + 7;
vector<vi> matmul(vector<vi> A, vector<vi> B) {
    int n = sz(A), m = sz(A[0]), p = sz(B[0]);
    assert(sz(B) == m);
    vector<vi> C(n, vi(p, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            for (int k = 0; k < m; k++)
                C[i][j] = (C[i][j] + 1LL * A[i][k] * B[k][j]) % (mod - 1);
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
int exp(ll n, ll k) {
    n %= mod;
    if (n == 0) return 0;
    k %= mod - 1;
    if (k < 0) k += mod - 1;
    ll r = 1;
    while (k) {
        if (k & 1) r = (r * n) % mod;
        n = (n * n) % mod;
        k >>= 1;
    }
    return r;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    const int k = 3;
    ll n, f[k], c;
    cin >> n >> f[0] >> f[1] >> f[2] >> c;
    vector<vi> M(k, vi(k, 0));
    for (int i = 1; i < k; i++) {
        M[i][i - 1] = 1;
        M[0][i - 1] = 1;
    }
    M[0][k - 1] = 1;
    M = matexp(M, n - 3);
    ll ans = exp(c, -n);
    for (int i = 0; i < k; i++) {
        f[i] = (f[i] * exp(c, i + 1)) % mod;
        ans = (ans * exp(f[i], M[0][k - i - 1])) % mod;
    }
    cout << ans << '\n';
}
