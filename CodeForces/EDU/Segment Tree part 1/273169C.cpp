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
const int inf = 1e9 + 7;
struct node {
    int mn, cnt;
    node(int v = inf) {
        mn = v;
        cnt = 1;
    }
    node operator+(const node& oth) {
        if (mn < oth.mn) return *this;
        if (oth.mn < mn) return oth;
        node r(mn);
        r.cnt = cnt + oth.cnt;
        return r;
    }
};
template <class node>
struct seg_tree {
    vector<node> t;
    int n;
    seg_tree() {}
    void build(vector<int>& a) {
        n = a.size();
        t.resize(2 * n);
        for (int i = 0; i < n; i++)
            t[i + n] = node(a[i]);
        for (int i = n - 1; i > 0; i--)
            t[i] = t[i << 1] + t[i << 1 | 1];
    }
    void update(int p, int x) {  // on 0-indexed p
        for (t[p += n] = node(x); p >>= 1;)
            t[p] = t[p << 1] + t[p << 1 | 1];
    }
    node query(int l, int r) {  // interval [l,r]
        node resl, resr;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resl = resl + t[l++];
            if (r & 1) resr = t[--r] + resr;
        }
        return resl + resr;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    seg_tree<node> stree;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    stree.build(a);
    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, v;
            cin >> i >> v;
            stree.update(i, v);
        }
        if (t == 2) {
            int l, r;
            cin >> l >> r;
            node res = stree.query(l, r - 1);
            cout << res.mn << ' ' << res.cnt << '\n';
        }
    }
}
