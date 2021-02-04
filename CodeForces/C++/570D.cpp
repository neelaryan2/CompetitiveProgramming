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
vector<vector<int>> adj, nodes, cnts;
vector<int> tin, tout;
string letters;
int T = 0;
void dfs(int v, int h) {
    tin[v] = T++;
    while (h >= (int)nodes.size()) {
        nodes.eb();
        cnts.eb(vi(1, 0));
    }
    nodes[h].eb(tin[v]);
    int cur = cnts[h].back();
    int c = letters[v] - 'a';
    cnts[h].eb(cur ^ (1 << c));
    for (int u : adj[v])
        dfs(u, h + 1);
    tout[v] = T;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    tin.resize(n);
    tout.resize(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        adj[--p].eb(i);
    }
    cin >> letters;
    dfs(0, 0);
    for (int _ = 0; _ < m; _++) {
        int v, h;
        cin >> v >> h;
        v--, h--;
        if (h >= nodes.size()) {
            puts("Yes");
            continue;
        }
        int l = lb(all(nodes[h]), tin[v]) - nodes[h].begin();
        int r = lb(all(nodes[h]), tout[v]) - nodes[h].begin();
        int par = cnts[h][r] ^ cnts[h][l];
        par = __builtin_popcount(par);
        puts((par <= 1) ? "Yes" : "No");
    }
}
