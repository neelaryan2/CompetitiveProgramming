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
struct seg_tree {
    vector<int> t;
    int n;
    seg_tree() {}
    int combine(int a, int b) {
        return a + b;
    }
    void build(vector<int>& a) {
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
    int query(int l, int r) {  // interval [l,r]
        int resl = 0, resr = 0;
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i & 1) a[i] *= -1;
    }
    seg_tree stree;
    stree.build(a);
    int m;
    cin >> m;
    for (int _ = 0; _ < m; _++) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 0) {
            l--;
            if (l & 1) r *= -1;
            stree.update(l, r);
        }
        if (t == 1) {
            l--, r--;
            int sum = stree.query(l, r);
            if (l & 1) sum *= -1;
            cout << sum << '\n';
        }
    }
}
