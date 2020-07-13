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
    void init(int m) {
        n = m;
        t.assign(4 * n, 0);
    }
    int query_aux(int v, int tl, int tr, int l, int r, int x, int lef) {
        if (l > r || t[v] < x || tr < lef) return -1;
        if (tl == tr) return tl;
        int tm = (tl + tr) / 2;
        int res = query_aux(v * 2, tl, tm, l, min(r, tm), x, lef);
        if (res == -1) res = query_aux(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x, lef);
        return res;
    }
    void update_aux(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
            return;
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update_aux(v * 2, tl, tm, pos, new_val);
        else
            update_aux(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
    void update(int i, int x) {
        return update_aux(1, 0, n - 1, i, x);
    }
    int query(int l, int r, int x, int lef) {
        return query_aux(1, 0, n - 1, l, r, x, lef);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> B(n + 10, 0), a(n);
    seg_tree stree;
    stree.init(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        stree.update(i, a[i]);
    }
    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, v;
            cin >> i >> v;
            stree.update(i, v);
        }
        if (t == 2) {
            int x, l;
            cin >> x >> l;
            int res = stree.query(0, n - 1, x, l);
            cout << res << '\n';
        }
    }
}
