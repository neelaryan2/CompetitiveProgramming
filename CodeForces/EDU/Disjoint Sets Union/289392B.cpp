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
using ppi = pair<pii, int>;
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

const ll inf = 1e11;

struct PersistentDSU {
    int comp;
    stack<vector<int>> states;
    vector<int> siz, par;
    PersistentDSU(int n = 0) {
        comp = n;
        par.resize(n);
        siz.resize(n);
        for (int i = 0; i < n; i++)
            makeset(i);
    }
    void makeset(int a) {
        par[a] = a;
        siz[a] = 1;
    }
    int root(int a) {
        if (par[a] == a) return a;
        return root(par[a]);
    }
    int unite(int a, int b) {
        a = root(a), b = root(b);
        if (a == b) return 0;
        if (siz[a] > siz[b])
            swap(a, b);
        states.push({b, siz[b], a, par[a]});
        siz[b] += siz[a];
        par[a] = b;
        comp--;
        return 1;
    }
    void rollback() {
        if (states.empty()) return;
        vector<int> s = states.top();
        states.pop();
        siz[s[0]] = s[1];
        par[s[2]] = s[3];
        comp++;
    }
};
void solve(int test) {
    int n, m, k;
    cin >> n >> m;
    vector<pii> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges.eb(u, v);
    }
    cin >> k;
    int szB = k / sqrtl(m);
    int numB = 1 + (m - 1) / szB;

    vector<vector<ppi>> q(numB);
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        q[u / szB].eb(mp(mp(v, u), i));
    }

    PersistentDSU dsu(n);

    vector<int> ans(k);
    for (int i = 0; i < numB; i++) {
        sort(all(q[i]));
        int ptr = 0, sz = q[i].size();
        int up = min((i + 1) * szB, m);

        while (ptr < sz && q[i][ptr].fi.fi < up) {
            ppi p = q[i][ptr++];
            int l = p.fi.se, id = p.se;
            int r = p.fi.fi, cnt = 0;

            for (int j = l; j <= r; j++)
                cnt += dsu.unite(edges[j].fi, edges[j].se);
            ans[id] = dsu.comp;
            while (cnt--)
                dsu.rollback();
        }

        int fuck = 0;
        for (int rpoint = up; ptr < sz; ptr++) {
            ppi p = q[i][ptr];
            int l = p.fi.se, id = p.se;
            int r = p.fi.fi, cnt = 0;

            while (rpoint <= r) {
                pii cur = edges[rpoint++];
                fuck += dsu.unite(cur.fi, cur.se);
            }

            for (int j = l; j < up; j++)
                cnt += dsu.unite(edges[j].fi, edges[j].se);
            ans[id] = dsu.comp;
            while (cnt--)
                dsu.rollback();
        }
        while (fuck--)
            dsu.rollback();
    }

    for (int i = 0; i < k; i++)
        cout << ans[i] << '\n';
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
