#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define mp make_pair
using pii = pair<int, int>;
using ll = long long;
typedef tree<pii, null_type, less<pii>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
int n, d;
ll ans = 0;
vector<int> par, p, siz;
vector<pii> edges;
vector<ordered_set> sets;
int root(int a) {
    if (par[a] == -1) par[a] = a;
    int _a = a;
    while (a != par[a]) a = par[a];
    par[_a] = a;
    return a;
}
void add(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    par[b] = a;
    siz[a] += siz[b];
    for (pii p : sets[b]) {
        int e = p.first;
        int hi = sets[a].order_of_key(mp(e + d, n));
        int lo = sets[a].order_of_key(mp(e - d, -1));
        ans += hi - lo;
    }
    for (pii e : sets[b]) sets[a].insert(e);
}
void init() {
    edges.resize(n - 1);
    p.resize(n - 1);
    par.assign(n, -1);
    siz.assign(n, 1);
    sets.resize(n);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> d;
    init();
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        sets[i].insert(mp(e, i));
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[i] = {u, v};
    }
    for (int& e : p) cin >> e, e--;
    reverse(p.begin(), p.end());
    vector<ll> fin(n - 1, 0);
    for (int i = 0; i < n - 1; i++) {
        pii e = edges[p[i]];
        fin[i] = ans;
        add(e.first, e.second);
    }
    reverse(fin.begin(), fin.end());
    for (ll& e : fin) cout << e << '\n';
}