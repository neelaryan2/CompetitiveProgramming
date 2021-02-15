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

const int N = 1000000 + 1;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
using my_map = unordered_map<long long, int, custom_hash>;
// using my_map = map<int, int>;

struct DSU {
    vector<int> par;
    DSU(int n = 0) {
        par.resize(n);
        iota(all(par), 0);
    }
    int root(int a) {
        if (a == par[a])
            return a;
        return par[a] = root(par[a]);
    }
    int unite(int a, int b) {
        a = root(a), b = root(b);
        if (a == b) return 0;
        par[a] = b;
        return 1;
    }
};

vector<int> p, a;
vector<vi> adj;
vector<my_map> vec;

void dfs(int v) {
    if (a[v] == 0) {
        ll pr = 1;
        while (p[v] != -1) {
            v = p[v];
            pr *= a[v];
            if (pr >= N) break;
            vec[v][pr]++;
        }
    } else {
        for (int u : adj[v])
            dfs(u);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n;

    p.resize(n);
    a.assign(n, 0);
    adj.resize(n);
    vec.resize(n);
    DSU dsu(n);

    vector<set<int>> sadj(n);

    p[0] = -1;
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        sadj[--p[i]].insert(i);
        a[p[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            int u = *sadj[i].begin();
            dsu.unite(i, u);
            sadj[i].erase(u);
            a[i]--;
            p[u] = p[i];
            if (p[i] != -1) {
                sadj[p[i]].erase(i);
                sadj[p[i]].insert(u);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        assert(sadj[i].size() == a[i]);
        if (sadj[i].empty()) continue;
        for (int j : sadj[i])
            adj[i].eb(j);
    }
    dfs(dsu.root(0));

    cin >> q;
    for (int i = 0; i < q; i++) {
        int v, w;
        cin >> v >> w;
        v = dsu.root(v - 1);
        int ans = w;
        for (pii u : vec[v]) {
            if (w % u.fi) continue;
            ans -= (w / u.fi) * u.se;
        }
        if (a[v] == 0) ans = 0;
        cout << ans << '\n';
    }
}
