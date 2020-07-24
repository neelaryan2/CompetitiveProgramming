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
struct seg_tree {
    vector<int> t;
    int n;
    void init(int m) {
        n = m;
        t.assign(4 * n, inf);
    }
    int query_aux(int v, int tl, int tr, int l, int r, int p) {
        if (l > r || t[v] > p) return 0;
        if (tl == tr) {
            t[v] = inf;
            return 1;
        }
        int tm = (tl + tr) / 2;
        int lef = query_aux(v * 2, tl, tm, l, min(r, tm), p);
        int righ = query_aux(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, p);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
        return lef + righ;
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
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
    void update(int i, int x) {
        return update_aux(1, 0, n - 1, i, x);
    }
    int query(int l, int r, int p) {
        return query_aux(1, 0, n - 1, l, r, p);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    seg_tree stree;
    stree.init(n);
    for (int _ = 0; _ < m; _++) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, h;
            cin >> i >> h;
            stree.update(i, h);
        }
        if (t == 2) {
            int l, r, p;
            cin >> l >> r >> p;
            int d = stree.query(l, --r, p);
            cout << d << '\n';
        }
    }
}
