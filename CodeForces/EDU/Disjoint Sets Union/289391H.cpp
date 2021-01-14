#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using ld = long double;
using pii = pair<ll, ll>;
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

const ll inf = 1e11;

struct DSU {
    int comp;
    vector<int> siz, par;
    DSU(int n = 0) {
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
        return par[a] = root(par[a]);
    }
    bool unite(int a, int b) {
        a = root(a), b = root(b);
        if (a == b) return false;
        if (siz[a] > siz[b])
            swap(a, b);
        siz[b] += siz[a];
        par[a] = b;
        comp--;
        return true;
    }
};
void solve(int test) {
    ll n, m, s;
    cin >> n >> m >> s;

    set<ppi> edges;
    ll sum = 0;
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.insert(mp(mp(-w, i + 1), mp(u, v)));
        sum += w;
    }

    DSU dsu(n);
    for (auto it = edges.begin(); it != edges.end();) {
        pii e = it->se;
        bool used = dsu.unite(e.fi, e.se);
        if (used) {
            sum += (it->fi).fi;
            it = edges.erase(it);
        } else
            it++;
        if (dsu.comp == 1) break;
    }
    auto it = edges.begin();
    while (it != edges.end() && sum > s) {
        sum += (it->fi).fi;
        it++;
    }
    vector<int> ans;
    while (it != edges.end()) {
        ans.eb((it->fi).se);
        it++;
    }
    sort(all(ans));
    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';
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
