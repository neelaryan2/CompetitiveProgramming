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
struct node {
    ll pref, suf, sum, seg;
    node(int v = 0) {
        pref = suf = sum = seg = v;
        if (v < 0) pref = suf = seg = 0;
    }
    node operator+(const node& oth) {
        node r;
        r.seg = max({seg, oth.seg, suf + oth.pref});
        r.pref = max(pref, sum + oth.pref);
        r.suf = max(suf + oth.sum, oth.suf);
        r.sum = sum + oth.sum;
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
    for (int& e : a) cin >> e;
    seg_tree<node> stree;
    stree.build(a);
    node ans = stree.query(0, n - 1);
    cout << ans.seg << '\n';
    while (m--) {
        int i, v;
        cin >> i >> v;
        stree.update(i, v);
        ans = stree.query(0, n - 1);
        cout << ans.seg << '\n';
    }
}
