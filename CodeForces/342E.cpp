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
template <typename T, bool maximum_mode = false>
struct RMQ {
    int n = 0;
    vector<T> values;
    vector<vector<int>> range_low;
    RMQ(const vector<T> &_values = {}) {
        if (!_values.empty())
            build(_values);
    }
    static int largest_bit(int x) {
        return 31 - __builtin_clz(x);
    }
    // Note: when `values[a] == values[b]`, returns b.
    int better_index(int a, int b) const {
        return (maximum_mode ? values[b] < values[a] : values[a] < values[b]) ? a : b;
    }
    void build(const vector<T> &_values) {
        values = _values;
        n = int(values.size());
        int levels = largest_bit(n) + 1;
        range_low.resize(levels);
        for (int k = 0; k < levels; k++)
            range_low[k].resize(n - (1 << k) + 1);
        for (int i = 0; i < n; i++)
            range_low[0][i] = i;
        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_low[k][i] = better_index(range_low[k - 1][i], range_low[k - 1][i + (1 << (k - 1))]);
    }
    // Note: breaks ties by choosing the largest index.
    int query_index(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        int level = largest_bit(b - a);
        return better_index(range_low[level][a], range_low[level][b - (1 << level)]);
    }
    T query_value(int a, int b) const {
        return values[query_index(a, b)];
    }
};
struct LCA {
    int n;
    vector<vector<int>> adj;
    vector<int> depth, euler, first_occurrence;
    RMQ<int> rmq;
    LCA() {}
    void init(const vector<vector<int>> &_adj = {}) {
        n = (int)_adj.size();
        adj = _adj;
        depth.resize(n);
        first_occurrence.resize(n);
    }
    void dfs(int node, int parent) {
        depth[node] = (parent == -1) ? 0 : depth[parent] + 1;
        first_occurrence[node] = euler.size();
        euler.push_back(node);
        for (int neighbor : adj[node])
            if (neighbor != parent) {
                dfs(neighbor, node);
                euler.push_back(node);
            }
    }
    void build(int root = 0) {
        dfs(root, -1);
        assert((int)euler.size() == 2 * n - 1);
        vector<int> euler_depths;
        for (int node : euler)
            euler_depths.push_back(depth[node]);
        rmq.build(euler_depths);
    }
    int lca(int a, int b) const {
        a = first_occurrence[a];
        b = first_occurrence[b];
        if (a > b) swap(a, b);
        return euler[rmq.query_index(a, b + 1)];
    }
    int dist(int a, int b) const {
        return depth[a] + depth[b] - 2 * depth[lca(a, b)];
    }
};
struct CentroidTree {
    vector<int> subtree_size;
    vector<int> centroid_parent;
    vector<set<int>> adj;
    void init(const vector<vector<int>> &_adj) {
        int n = _adj.size();
        centroid_parent.resize(n);
        subtree_size.resize(n);
        adj.resize(n);
        for (int i = 0; i < n; i++)
            for (int v : _adj[i])
                adj[i].insert(v);
    }
    int dfs(int node, int parent = -1) {
        subtree_size[node] = 1;
        for (int neighbor : adj[node])
            if (neighbor != parent)
                subtree_size[node] += dfs(neighbor, node);
        return subtree_size[node];
    }
    int centroid(int root) {
        int n = dfs(root);
        bool found;
        // Repeatedly move to the subtree that is at least half of the tree, if such a subtree exists.
        do {
            found = false;
            int root_size = subtree_size[root];
            for (int neighbor : adj[root]) {
                int cur_size = subtree_size[neighbor];
                if (cur_size > root_size) continue;
                if (2 * cur_size < n) continue;
                root = neighbor, found = true;
                break;
            }
        } while (found);
        return root;
    }
    void decompose(int root, int cent_parent = -1) {
        root = centroid(root);
        centroid_parent[root] = cent_parent;
        for (int neighbor : adj[root]) {
            // Erase the edge from e.node back to root.
            adj[neighbor].erase(root);
            decompose(neighbor, root);
        }
        adj[root].clear();
    }
};
LCA lca;
CentroidTree ctree;
vector<int> ans;
const int inf = 1e9 + 7;
void red(int v) {
    for (int p = v; p != -1; p = ctree.centroid_parent[p])
        ans[p] = min(ans[p], lca.dist(p, v));
}
int nearest(int v) {
    int ret = inf;
    for (int p = v; p != -1; p = ctree.centroid_parent[p])
        ret = min(ret, lca.dist(v, p) + ans[p]);
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    ans.assign(n, inf);
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    lca.init(adj);
    lca.build(0);
    ctree.init(adj);
    ctree.decompose(0);
    red(0);
    for (int _ = 0; _ < m; _++) {
        int t, v;
        cin >> t >> v;
        t--, v--;
        if (t == 0) {
            red(v);
        }
        if (t == 1) {
            cout << nearest(v) << '\n';
        }
    }
}
