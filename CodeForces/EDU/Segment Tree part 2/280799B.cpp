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
    vector<int> t, lazy;
    int n;
    void init(int m) {
        n = m;
        t.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }
    void push(int v, int l, int r) {
        if (!lazy[v]) return;
        int vl = v * 2, vr = v * 2 + 1;
        lazy[vl] ^= 1;
        lazy[vr] ^= 1;
        t[vl] = l - t[vl];
        t[vr] = r - t[vr];
        lazy[v] = 0;
    }
    void _modify(int v, int tl, int tr, int l, int r) {
        if (l > r) return;
        if (l == tl && tr == r) {
            t[v] = (tr - tl + 1) - t[v];
            lazy[v] ^= 1;
        } else {
            int tm = (tl + tr) / 2;
            push(v, tm - tl + 1, tr - tm);
            _modify(v * 2, tl, tm, l, min(r, tm));
            _modify(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }
    int _query(int v, int tl, int tr, int k) {
        if (tl == tr) return tl;
        int tm = (tl + tr) / 2;
        push(v, tm - tl + 1, tr - tm);
        if (k <= t[v * 2])
            return _query(v * 2, tl, tm, k);
        else
            return _query(v * 2 + 1, tm + 1, tr, k - t[v * 2]);
    }
    void modify(int l, int r) {
        return _modify(1, 0, n - 1, l, r);
    }
    int query(int k) {
        return _query(1, 0, n - 1, k);
    }
};

void solve(int test) {
    int n, m;
    cin >> n >> m;
    seg_tree_lazy stree;
    stree.init(n);

    while (m--) {
        int t, l, r;
        cin >> t;
        if (t == 2) {
            int k;
            cin >> k;
            cout << stree.query(k + 1) << '\n';
        } else {
            int l, r;
            cin >> l >> r;
            stree.modify(l, --r);
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
