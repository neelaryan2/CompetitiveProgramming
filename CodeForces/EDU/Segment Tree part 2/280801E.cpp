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

struct seg_tree_lazy {
    vector<ll> dec_op, inc_op;
    int n, h;
    seg_tree_lazy() {}
    void init(int m = 0) {
        n = m;
        h = 32 - __builtin_clz(n);
        dec_op.assign(2 * n, 0);
        inc_op.assign(2 * n, 0);
    }
    void inc(int p, ll value, int c) {
        // apply to children
        inc_op[p] = max(inc_op[p], value);
        dec_op[p] = max(dec_op[p], value);
    }
    void dec(int p, ll value, int c) {
        // apply to children
        dec_op[p] = min(dec_op[p], value);
        inc_op[p] = min(inc_op[p], value);
    }
    void apply(int c, int p) {
        dec_op[c] = min(dec_op[c], dec_op[p]);
        dec_op[c] = max(dec_op[c], inc_op[p]);
        inc_op[c] = max(inc_op[c], inc_op[p]);
        inc_op[c] = min(inc_op[c], dec_op[p]);
    }
    void push_down(int l, int r = -1) {
        if (r == -1) r = l;
        int s = h, k = 1 << (h - 1);
        for (l += n, r += n; s > 0; --s, k >>= 1) {
            for (int i = l >> s; i <= r >> s; ++i) {
                apply(i << 1, i);
                apply(i << 1 | 1, i);
                inc_op[i] = 0, dec_op[i] = inf;
            }
        }
    }
    void decrease(int l, int r, ll v) {
        if (r < l || r >= n || l < 0) return;
        int _l = l, _r = r;
        l += n, r += n + 1;
        push_down(_l), push_down(_r);
        for (int c = 1; l < r; l >>= 1, r >>= 1, c <<= 1) {
            if (l & 1) dec(l++, v, c);
            if (r & 1) dec(--r, v, c);
        }
    }
    void increase(int l, int r, ll v) {
        if (r < l || r >= n || l < 0) return;
        int _l = l, _r = r;
        l += n, r += n + 1;
        push_down(_l), push_down(_r);
        for (int c = 1; l < r; l >>= 1, r >>= 1, c <<= 1) {
            if (l & 1) inc(l++, v, c);
            if (r & 1) inc(--r, v, c);
        }
    }
};

void print(seg_tree_lazy& tree) {
    int n = tree.n;
    for (int i = 1; i < 2 * n; i++) {
        int t = tree.dec_op[i];
        cerr << "(" << (t == inf ? "-" : to_string(t)) << ",";
        cerr << tree.inc_op[i] << ")";

        if ((i & (i + 1)) == 0)
            cerr << endl;
        else
            cerr << ",";
    }
    cerr << endl;
}

void solve(int test) {
    int n, m;
    cin >> n >> m;

    seg_tree_lazy stree;
    stree.init(n);

    while (m--) {
        ll t, l, r, v;
        cin >> t >> l >> r >> v;
        if (t == 1) {
            stree.increase(l, r, v);
        }
        if (t == 2) {
            stree.decrease(l, r, v);
        }
    }
    stree.push_down(0, n - 1);

    for (int i = n; i < 2 * n; i++) {
        int lo = stree.inc_op[i];
        int hi = stree.dec_op[i];
        assert(lo == hi);
        cout << min(lo, hi) << '\n';
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
