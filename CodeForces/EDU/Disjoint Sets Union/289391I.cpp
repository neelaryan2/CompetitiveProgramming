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
using ppi = pair<ll, pii>;
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
    vector<int> siz, par, len;
    DSU(int n = 0) {
        len.resize(n);
        par.resize(n);
        siz.resize(n);
        for (int i = 0; i < n; i++)
            makeset(i);
    }
    void makeset(int a) {
        par[a] = a;
        siz[a] = 1;
        len[a] = 0;
    }
    pii root(int a) {
        if (par[a] == a) return mp(a, 0);
        pii lead = root(par[a]);
        len[a] ^= len[par[a]];
        par[a] = lead.fi;
        return mp(par[a], len[a]);
    }
    void unite(int a, int b) {
        pii pa = root(a), pb = root(b);
        a = pa.fi, b = pb.fi;
        if (a == b) return;
        if (siz[a] > siz[b])
            swap(a, b), swap(pa, pb);
        siz[b] += siz[a];
        par[a] = b;
        len[a] = (1 + pa.se + pb.se) % 2;
    }
};
void solve(int test) {
    int n, m;
    cin >> n >> m;

    DSU dsu(n);
    int shift = 0;
    for (int i = 0; i < m; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        int x = (a + shift) % n;
        int y = (b + shift) % n;
        if (t == 0) {
            dsu.unite(x, y);
        }
        if (t == 1) {
            x = dsu.root(x).se;
            y = dsu.root(y).se;
            if (x == y) shift = (shift + 1) % n;
            cout << ((x == y) ? "YES\n" : "NO\n");
        }
    }
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
