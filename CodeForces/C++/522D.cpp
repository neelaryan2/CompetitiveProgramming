#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ppi = pair<pii, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const int inf = 1e6;
struct segtree {
    vector<int> t;
    int n;
    segtree() {}
    int combine(int a, int b) {
        return min(a, b);
    }
    void build(vector<int>& a) {
        n = a.size();
        t.resize(2 * n);
        for (int i = 0; i < n; i++)
            t[i + n] = a[i];
        for (int i = n - 1; i > 0; i--)
            t[i] = combine(t[i << 1], t[i << 1 | 1]);
    }
    void update(int p, int x) {  // on 0-indexed p
        for (t[p += n] = x; p >>= 1;)
            t[p] = combine(t[p << 1], t[p << 1 | 1]);
    }
    int query(int l, int r) {  // interval [l,r]
        int resl = inf, resr = inf;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resl = combine(resl, t[l++]);
            if (r & 1) resr = combine(t[--r], resr);
        }
        return combine(resl, resr);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> nxt(n, inf), dist(n, inf);
    map<int, int> ind;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        auto it = ind.find(e);
        if (it != ind.end()) {
            nxt[it->se] = i;
            dist[i] = i - it->se;
        }
        ind[e] = i;
    }
    vector<ppi> q(m);
    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        q[i] = {{l, r}, i};
    }
    sort(all(q));
    segtree tree;
    tree.build(dist);
    int pnter = 0, res;
    for (ppi& p : q) {
        int l = p.fi.fi, r = p.fi.se, id = p.se;
        while (pnter < l) {
            if (nxt[pnter] != inf)
                tree.update(nxt[pnter], inf);
            pnter++;
        }
        res = tree.query(l, r);
        if (res == inf) res = -1;
        ans[id] = res;
    }
    for (int i : ans) cout << i << '\n';
}
