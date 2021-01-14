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

vector<int> par, siz;

void makeset(int v) {
    par[v] = v;
    siz[v] = 1;
}
int root(int a) {
    int _a = a;
    while (a != par[a]) a = par[a];
    par[_a] = a;
    return a;
}
void unite(int a, int b) {
    a = root(a), b = root(b);
    if (a == b) return;
    if (siz[a] < siz[b])
        swap(a, b);
    siz[a] += siz[b];
    par[b] = a;
}

void solve(int test) {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pii> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[i] = mp(u, v);
    }

    vector<pii> uv(k);
    vector<bool> typ(k);

    for (int i = 0; i < k; i++) {
        string t;
        int u, v;
        cin >> t >> u >> v;
        u--, v--;
        typ[i] = (t == "cut");
        uv[i] = mp(u, v);
    }

    par.resize(n);
    siz.resize(n);
    for (int i = 0; i < n; i++)
        makeset(i);

    vector<bool> ans;
    for (int i = k - 1; i >= 0; i--) {
        int u = uv[i].fi, v = uv[i].se;
        if (typ[i]) {
            unite(u, v);
        } else {
            ans.eb(root(u) == root(v));
        }
    }

    reverse(all(ans));
    for (bool b : ans)
        cout << (b ? "YES\n" : "NO\n");
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
