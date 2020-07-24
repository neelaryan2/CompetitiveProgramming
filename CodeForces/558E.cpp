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

struct seg_tree_assign {
    vector<int> t, lazy;
    vector<bool> dont;
    int n;
    void init(int m) {
        n = m;
        t.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        dont.assign(4 * n, true);
    }
    void push(int v, int k, bool leaf) {
        if (!dont[v]) {
            t[v] = lazy[v] * k;
            if (!leaf) {
                lazy[v * 2] = lazy[v * 2 + 1] = lazy[v];
                dont[v * 2] = dont[v * 2 + 1] = false;
            }
            lazy[v] = 0, dont[v] = true;
        }
    }
    void assign_aux(int v, int tl, int tr, int l, int r, int new_val) {
        if (l > r) return push(v, tr - tl + 1, tl == tr);
        if (l == tl && tr == r) {
            lazy[v] = new_val, dont[v] = false;
            push(v, tr - tl + 1, tl == tr);
        } else {
            push(v, tr - tl + 1, tl == tr);
            int tm = (tl + tr) / 2;
            assign_aux(v * 2, tl, tm, l, min(r, tm), new_val);
            assign_aux(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, new_val);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }
    int query_aux(int v, int tl, int tr, int l, int r) {
        push(v, tr - tl + 1, tl == tr);
        if (l > r) return 0;
        if (l == tl && tr == r) return t[v];
        int tm = (tl + tr) / 2;
        int ret = query_aux(v * 2, tl, tm, l, min(r, tm)) +
                  query_aux(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        t[v] = t[v * 2] + t[v * 2 + 1];
        return ret;
    }
    void assign(int l, int r, int x) {
        return assign_aux(1, 0, n - 1, l, r, x);
    }
    int query(int l, int r) {
        return query_aux(1, 0, n - 1, l, r);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    seg_tree_assign stree[26];
    for (int i = 0; i < 26; i++)
        stree[i].init(n);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        stree[c - 'a'].assign(i, i, 1);
    }
    for (int _ = 0; _ < q; _++) {
        int l, r, k;
        cin >> l >> r >> k;
        l--, r--;
        vector<int> cnt(26);
        for (int i = 0; i < 26; i++) {
            cnt[i] = stree[i].query(l, r);
            stree[i].assign(l, r, 0);
        }
        if (k) {
            for (int i = 0; i < 26; i++) {
                stree[i].assign(l, l + cnt[i] - 1, 1);
                l += cnt[i];
            }
        } else {
            for (int i = 26 - 1; i >= 0; i--) {
                stree[i].assign(l, l + cnt[i] - 1, 1);
                l += cnt[i];
            }
        }
        assert(l == r + 1);
    }
    for (int i = 0; i < n; i++) {
        char c = '*';
        for (int j = 0; j < 26; j++) {
            if (stree[j].query(i, i)) {
                c = char(j + 'a');
                break;
            }
        }
        cout << c;
    }
    cout << '\n';
}
