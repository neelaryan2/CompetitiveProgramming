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
using ppi = pair<pii, ll>;
using vi = vector<int>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
struct node {
    ll val;
    node(ll v = 0) : val(v) {}
    node operator+(const node& oth) { return node(max(val, oth.val)); }
};
template <class node>
struct seg_tree {
    vector<node> t;
    int n;
    seg_tree() {}
    void build(int m) {
        n = m;
        t.resize(2 * n);
    }
    void update(int p, ll x) {  // on 0-indexed p
        if (t[p + n].val > x) return;
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
    seg_tree<node> stree;
    int n;
    cin >> n;
    vector<ppi> segs(n);
    vector<int> v;
    for (ppi& p : segs) {
        cin >> p.fi.fi >> p.fi.se >> p.se;
        v.eb(p.fi.fi), v.eb(p.fi.se);
    }
    sort(all(v));
    int k = unique(all(v)) - v.begin();
    v.resize(k);
    for (ppi& p : segs) {
        p.fi.fi = lb(all(v), p.fi.fi) - v.begin();
        p.fi.se = lb(all(v), p.fi.se) - v.begin();
        swap(p.fi.fi, p.fi.se);
    }
    sort(rall(segs));
    trace(segs);
    stree.build(k);
    ll ans = 0;
    for (ppi& p : segs) {
        ll res = stree.query(0, p.fi.fi - 1).val;
        p.se += res;
        ans = max(ans, p.se);
        stree.update(p.fi.se, p.se);
    }
    cout << ans << '\n';
}
