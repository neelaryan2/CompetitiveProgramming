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

struct DSU {
    vector<int> siz, par;
    DSU(int n = 0) {
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
    void unite(int a, int b) {
        a = root(a), b = root(b);
        if (a == b) return;
        siz[b] += siz[a];
        par[a] = b;
    }
};
void solve(int test) {
    int n, q;
    cin >> n >> q;
    DSU dsu(n + 1);
    DSU seg(n + 1);

    for (int i = 0; i < q; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        x--, y--;
        if (x > y) swap(x, y);
        if (t == 1) {
            dsu.unite(x, y);
        }
        if (t == 2) {
            while (true) {
                x = seg.root(x);
                if (x >= y) break;
                dsu.unite(x, x + 1);
                seg.unite(x, x + 1);
            }
        }
        if (t == 3) {
            x = dsu.root(x);
            y = dsu.root(y);
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
