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
const int K = 2;
int mod = 1e9 + 7;
struct mat {
    int m[K][K];
    mat(int c = 1) {
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K; j++) {
                m[i][j] = 0;
                if (i == j) m[i][j] = c;
            }
        }
    }
    void read() {
        for (int i = 0; i < K; i++)
            for (int j = 0; j < K; j++)
                cin >> m[i][j];
    }
    void print() {
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K; j++) {
                cout << m[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    mat operator*(const mat& oth) {
        mat c(0);
        for (int i = 0; i < K; i++)
            for (int j = 0; j < K; j++)
                for (int k = 0; k < K; k++)
                    c.m[i][j] = (c.m[i][j] + m[i][k] * oth.m[k][j]) % mod;
        return c;
    }
};
struct seg_tree {
    vector<mat> t;
    int n;
    seg_tree() {}
    mat combine(mat a, mat b) {
        return a * b;
    }
    void build(vector<mat>& a) {
        n = a.size();
        t.resize(2 * n);
        for (int i = 0; i < n; i++)
            t[i + n] = a[i];
        for (int i = n - 1; i > 0; i--)
            t[i] = combine(t[i << 1], t[i << 1 | 1]);
    }
    void update(int p, int x) {  // on 0-indexed p
        for (t[p += n] = x; p >>= 1;)
            t[p] = combine(t[p << 1], t[p << 1 | 1]);
    }
    mat query(int l, int r) {  // interval [l,r]
        mat resl, resr;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resl = combine(resl, t[l++]);
            if (r & 1) resr = combine(t[--r], resr);
        }
        return combine(resl, resr);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int r, n, m;
    cin >> r >> n >> m;
    mod = r;
    vector<mat> a(n);
    for (mat& t : a) t.read();
    seg_tree stree;
    stree.build(a);
    while (m--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        mat c = stree.query(l, r);
        c.print();
    }
}
