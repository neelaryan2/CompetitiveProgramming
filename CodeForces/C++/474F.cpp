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
#define rall(v) (v).rbegin(), (v).rend()

const int inf = 1e9 + 7;

struct node {
    int v;
    node(int a = 0) { v = a; }
    node operator+(const node& oth) {
        return node(__gcd(v, oth.v));
    }
};
// point updates and range sum queries
template <class node>
struct seg_tree {
    const static int NEUTRAL = 0;
    vector<node> t;
    int n;
    seg_tree() {}
    void init(int m) {
        n = m;
        t.assign(2 * n, node(NEUTRAL));
    }
    void build(vector<node> a) {
        init(a.size());
        for (int i = 0; i < n; i++)
            t[i + n] = a[i];
        for (int i = n - 1; i > 0; i--)
            calc(i);
    }
    void calc(int i) {
        // pull from children
        t[i] = t[i << 1] + t[i << 1 | 1];
    }
    void modify(int p, node x) {  // on 0-indexed p
        for (t[p += n] = x; p >>= 1;)
            calc(p);
    }
    node query(int l, int r) {  // interval [l,r]
        node resl(NEUTRAL), resr(NEUTRAL);
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resl = resl + t[l++];
            if (r & 1) resr = t[--r] + resr;
        }
        return resl + resr;
    }
};
void solve(int test) {
    int n;
    cin >> n;
    vector<node> a(n);
    vector<pii> vec;
    for (int i = 0; i < n; i++) {
        cin >> a[i].v;
        vec.eb(a[i].v, i);
    }
    sort(all(vec));
    seg_tree<node> stree;
    stree.build(a);
    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int ans = r - l + 1;
        int g = stree.query(l, r).v;
        l = lb(all(vec), mp(g, l)) - vec.begin();
        r = ub(all(vec), mp(g, r)) - vec.begin();
        trace(l, r, g, vec);
        ans -= r - l;
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
    }
}
