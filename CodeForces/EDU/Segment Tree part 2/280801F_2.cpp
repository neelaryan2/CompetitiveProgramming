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

const int NO_OP = INT_MIN;

vector<int> base;
struct node {
    int len, sum, mx, lazy;
    node(int l = 0) {
        len = l;
        sum = mx = 0;
        lazy = NO_OP;
    }
};
struct seg_tree_lazy {
    vector<node> t;
    int n;
    void init(int m) {
        n = m;
        t.assign(4 * n, 0);
        build(1, 0, n - 1);
    }
    void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = node(base[tl + 1] - base[tl]);
            return;
        }
        int tm = (tl + tr) / 2;
        int vl = v * 2, vr = v * 2 + 1;
        build(vl, tl, tm);
        build(vr, tm + 1, tr);
        t[v].sum = t[vl].sum + t[vr].sum;
        t[v].mx = max(t[vl].mx, t[vl].sum + t[vr].mx);
        t[v].len = t[vl].len + t[vr].len;
    }
    void push(int v) {
        if (t[v].lazy == NO_OP) return;
        int vl = v * 2, vr = v * 2 + 1;
        t[vl].lazy = t[v].lazy, t[vr].lazy = t[v].lazy;
        t[vl].sum = t[v].lazy * t[vl].len;
        t[vr].sum = t[v].lazy * t[vr].len;
        t[vl].mx = t[vl].sum, t[vr].mx = t[vr].sum;
        t[v].lazy = NO_OP;
    }
    void _modify(int v, int tl, int tr, int l, int r, int x) {
        if (l > r) return;
        if (l == tl && tr == r) {
            t[v].sum = t[v].len * x;
            t[v].mx = t[v].sum;
            t[v].lazy = x;
        } else {
            int tm = (tl + tr) / 2;
            int vl = v * 2, vr = v * 2 + 1;
            push(v);
            _modify(vl, tl, tm, l, min(r, tm), x);
            _modify(vr, tm + 1, tr, max(l, tm + 1), r, x);
            t[v].sum = t[vl].sum + t[vr].sum;
            t[v].mx = max(t[vl].mx, t[vl].sum + t[vr].mx);
            t[v].len = t[vl].len + t[vr].len;
        }
    }
    int _query(int v, int tl, int tr, int k) {
        if (t[v].mx <= k) return t[v].len;
        if (tl == tr) {
            assert(t[v].sum % t[v].len == 0);
            int d = t[v].sum / t[v].len;
            return k / d;
        }
        int tm = (tl + tr) / 2;
        push(v);
        int vl = v * 2;
        if (k < t[vl].mx)
            return _query(vl, tl, tm, k);
        else
            return t[vl].len + _query(v * 2 + 1, tm + 1, tr, k - t[vl].sum);
    }
    void modify(int l, int r, int x) {
        return _modify(1, 0, n - 1, l, r, x);
    }
    int query(int k) {
        return _query(1, 0, n - 1, k);
    }
};
void solve(int test) {
    int N;
    cin >> N;

    base.assign(2, 1);
    base[1] = N + 1;
    vector<array<int, 3>> q;

    while (true) {
        string s;
        cin >> s;
        int l, r, x;
        if (s == "E") break;
        if (s == "Q") {
            cin >> x;
            q.pb({-1, -1, x});
        }
        if (s == "I") {
            cin >> l >> r >> x;
            base.eb(l), base.eb(r + 1);
            q.pb({l, r + 1, x});
        }
    }

    sort(all(base));
    int n = unique(all(base)) - base.begin();
    base.resize(n);

    seg_tree_lazy stree;
    stree.init(n - 1);

    for (auto v : q) {
        int l, r, x;
        l = v[0], r = v[1], x = v[2];
        if (l == -1) {
            x = stree.query(x);
            cout << x << '\n';
        } else {
            l = lb(all(base), l) - base.begin();
            r = lb(all(base), r) - base.begin() - 1;
            stree.modify(l, r, x);
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
        cout << '\n';
    }
}