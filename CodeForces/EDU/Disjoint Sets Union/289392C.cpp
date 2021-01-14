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
using ppi = pair<pii, pii>;
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

struct PersistentDSU {
    int comp, ptr;
    vector<int> siz, par;
    stack<int> states;
    PersistentDSU(int n = 0) {
        comp = n;
        par.resize(n);
        siz.assign(n, 1);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }
    int root(int a) {
        while (a != par[a])
            a = par[a];
        return a;
    }
    int unite(int a, int b) {
        a = root(a), b = root(b);
        if (a == b) return 0;
        if (siz[a] > siz[b])
            swap(a, b);
        states.push(a);
        siz[b] += siz[a];
        par[a] = b;
        comp--;
        return 1;
    }
    bool rollback(int cnt = 1) {
        while (cnt--) {
            if (states.empty())
                return false;
            int s = states.top();
            states.pop();
            siz[par[s]] -= siz[s];
            par[s] = s;
            comp++;
        }
        return true;
    }
};

PersistentDSU dsu;
vector<int> ans;

void rec(int l, int r, vector<ppi>& modifiers) {
    if (l >= r) return;
    bool leaf = (l == r - 1);
    int cnt = 0, m = (l + r) / 2;
    vector<ppi> new_mod_l, new_mod_r;
    for (ppi pp : modifiers) {
        int ql = pp.se.fi, qr = pp.se.se;
        if (ql <= l && r <= qr)
            cnt += dsu.unite(pp.fi.fi, pp.fi.se);
        else if (!leaf) {
            if (max(ql, l) < min(qr, m))
                new_mod_l.eb(pp);
            if (max(ql, m) < min(qr, r))
                new_mod_r.eb(pp);
        }
    }
    if (leaf) {
        if (ans[l] == -2)
            ans[l] = dsu.comp;
    } else {
        rec(l, m, new_mod_l);
        rec(m, r, new_mod_r);
    }
    assert(dsu.rollback(cnt));
}
void solve(int test) {
    int n, m;
    cin >> n >> m;

    map<pii, int> edges;
    vector<ppi> modifiers;
    ans.assign(m, -1);

    for (int i = 0; i < m; i++) {
        string t;
        cin >> t;
        if (t == "?") {
            ans[i] = -2;
            continue;
        }
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        pii p = mp(--x, --y);

        auto it = edges.find(p);
        if (it == edges.end()) {
            edges[p] = -1;
            it = edges.find(p);
        }

        if (t == "+") {
            if (it->se == -1)
                it->se = i;
        }
        if (t == "-") {
            if (it->se != -1) {
                modifiers.eb(mp(p, mp(it->se, i)));
                it->se = -1;
            }
        }
    }
    int cnt = m;
    for (auto pp : edges)
        if (pp.se != -1)
            modifiers.eb(mp(pp.fi, mp(pp.se, cnt++)));
    edges.clear();

    dsu = PersistentDSU(n);
    rec(0, m, modifiers);

    for (int i : ans)
        if (i != -1)
            cout << i << '\n';
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