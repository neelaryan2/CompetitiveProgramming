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
struct LinkCut {
    struct node {
        int p, ch[2], sz, id, maxid;
        ll val, sub, lazy;
        bool flip;
        node(int i = 0, int v = 0) {
            p = ch[0] = ch[1] = -1;
            if (i != -1) id = maxid = i;
            val = sub = v;
            flip = lazy = 0;
            sz = 1;
        }
    };
    vector<node> t;
    LinkCut(int n = 0) {
        t.resize(n);
        for (int i = 0; i < n; i++)
            t[i] = node(i);
    }
    void push(int x) {
        if (x == -1) return;
        int &l = t[x].ch[0], &r = t[x].ch[1];
        if (t[x].lazy) {
            t[x].val += t[x].lazy, t[x].sub += t[x].lazy * t[x].sz;
            if (l + 1) t[l].lazy += t[x].lazy;
            if (r + 1) t[r].lazy += t[x].lazy;
        }
        if (t[x].flip) {
            swap(l, r);
            if (l + 1) t[l].flip ^= 1;
            if (r + 1) t[r].flip ^= 1;
        }
        t[x].lazy = 0, t[x].flip = 0;
    }
    void pull(int x) {
        if (x == -1) return;
        t[x].sz = 1, t[x].sub = t[x].val, t[x].maxid = t[x].id;
        for (int i = 0; i < 2; i++) {
            int c = t[x].ch[i];
            if (c == -1) continue;
            push(c);
            t[x].sz += t[c].sz;
            t[x].maxid = max(t[x].maxid, t[c].maxid);
            t[x].sub += t[c].sub;
        }
    }
    bool is_root(int x) {
        if (t[x].p == -1) return true;
        int l = t[t[x].p].ch[0], r = t[t[x].p].ch[1];
        return (l != x && r != x);
    }
    void rotate(int x) {
        int p = t[x].p, pp = t[p].p;
        if (!is_root(p)) t[pp].ch[t[pp].ch[1] == p] = x;
        bool d = (t[p].ch[0] == x);
        t[p].ch[!d] = t[x].ch[d], t[x].ch[d] = p;
        if (t[p].ch[!d] + 1) t[t[p].ch[!d]].p = p;
        t[x].p = pp, t[p].p = x;
        pull(p), pull(x);
    }
    int splay(int x) {
        while (!is_root(x)) {
            int p = t[x].p, pp = t[p].p;
            if (!is_root(p)) push(pp);
            push(p), push(x);
            if (!is_root(p))
                rotate((t[pp].ch[0] == p) ^ (t[p].ch[0] == x) ? x : p);
            rotate(x);
        }
        return push(x), x;
    }
    int access(int v) {
        int last = -1;
        for (int w = v; w + 1; pull(last = w), splay(v), w = t[v].p)
            splay(w), t[w].ch[1] = (last == -1 ? -1 : v);
        return last;
    }
    int find_root(int v) {
        access(v), push(v);
        while (t[v].ch[0] + 1) v = t[v].ch[0], push(v);
        return splay(v);
    }
    bool connected(int v, int w) {
        access(v), access(w);
        return v == w ? true : t[v].p != -1;
    }
    void rootify(int v) {
        access(v);
        t[v].flip ^= 1;
    }
    int query(int v, int w) {
        rootify(w), access(v);
        return v;
    }
    void update(int v, int w, int x) {
        rootify(w), access(v);
        t[v].lazy += x;
    }
    void link(int v, int w) {
        rootify(w);
        t[w].p = v;
    }
    void cut(int v, int w) {
        rootify(w), access(v);
        t[v].ch[0] = t[t[v].ch[0]].p = -1;
    }
    int lca(int v, int w) {
        access(v);
        return access(w);
    }
};
LinkCut lc;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int out = 0;
    vector<int> p(n + 1);
    lc = LinkCut(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (i + p[i] <= n) lc.link(i + p[i], i);
        if (i + p[i] > n) lc.link(out, i);
    }
    while (m--) {
        int t, a, b;
        cin >> t >> a;
        if (t == 0) {
            cin >> b;
            if (a + p[a] <= n) lc.cut(a + p[a], a);
            if (a + p[a] > n) lc.cut(out, a);
            p[a] = b;
            if (a + p[a] <= n) lc.link(a + p[a], a);
            if (a + p[a] > n) lc.link(out, a);
        }
        if (t == 1) {
            a = lc.query(out, a);
            int ans = lc.t[a].sz - 1;
            lc.push(a);
            a = lc.t[a].ch[0];
            lc.push(a);
            while (lc.t[a].ch[1] != -1) 
                a = lc.t[a].ch[1], lc.push(a);
            cout << lc.t[a].id << ' ' << ans << '\n';
        }
    }
}
