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
const static int NO_OP = INT_MAX;

struct seg_tree_lazy {
    vector<ll> t, d;
    int n, h;
    seg_tree_lazy() {}
    void init(int m = 0) {
        n = m;
        h = 32 - __builtin_clz(n);
        d.assign(n, NO_OP);
        t.assign(2 * n, 0);
    }
    void build(vector<int> a) {
        init(a.size());
        for (int i = 0; i < n; i++)
            t[i + n] = a[i];
        push_up(0, n - 1);
    }
    // c is the size of segment
    void calc(int p, int c) {
        // pull from children
        if (d[p] == NO_OP)
            t[p] = t[p << 1] + t[p << 1 | 1];
        else
            t[p] = d[p] * c;
    }
    void apply(int p, ll value, int c) {
        // apply to children
        if (p < n) d[p] = value;
        t[p] = value * c;
    }
    void push_up(int l, int r = -1) {
        if (r == -1) r = l;
        l += n, r += n;
        for (int k = 2; l > 1; k <<= 1) {
            l >>= 1, r >>= 1;
            for (int i = r; i >= l; --i)
                calc(i, k);
        }
    }
    void push_down(int l, int r = -1) {
        if (r == -1) r = l;
        int s = h, k = 1 << (h - 1);
        for (l += n, r += n; s > 0; --s, k >>= 1) {
            for (int i = l >> s; i <= r >> s; ++i) {
                if (d[i] == NO_OP) continue;
                apply(i << 1, d[i], k);
                apply(i << 1 | 1, d[i], k);
                d[i] = NO_OP;
            }
        }
    }
    void add(int l, int r, int v) {
        if (r < l || r >= n || l < 0) return;
        int _l = l, _r = r;
        l += n, r += n + 1;
        push_down(_l), push_down(_r);
        for (int c = 1; l < r; l >>= 1, r >>= 1, c <<= 1) {
            if (l & 1) apply(l++, v, c);
            if (r & 1) apply(--r, v, c);
        }
        push_up(_l), push_up(_r);
    }
    ll query(int l, int r) {
        ll res = 0;
        if (r < l || r >= n || l < 0)
            return res;
        push_down(l), push_down(r);
        l += n, r += n + 1;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += t[l++];
            if (r & 1) res += t[--r];
        }
        return res;
    }
};

void solve(int test) {
    int n, m;
    cin >> n >> m;
    seg_tree_lazy stree;
    stree.build(vector<int>(n, 0));
    while (m--) {
        ll t, l, r, v;
        cin >> t >> l >> r;
        r--;
        if (t == 1) {
            cin >> v;
            stree.add(l, r, v);
        }
        if (t == 2) {
            v = stree.query(l, r);
            cout << v << '\n';
        }
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
