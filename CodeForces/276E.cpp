#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
vector<vi> arr, adj;
vi dist, deg, pos;
void dfs(int v, int p, int i, int d = 1) {
    arr[i].pb(v);
    dist[v] = d;
    pos[v] = i;
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs(u, v, i, d + 1);
    }
}
void add(vector<int>& B, int i, int x) {
    for (; i < B.size(); i += i & (-i))
        B[i] += x;
}
int get(vector<int>& B, int i) {
    int sum = 0;
    for (; i > 0; i -= i & (-i))
        sum += B[i];
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    adj.resize(n);
    deg.assign(n, 0);
    dist.assign(n, 0);
    pos.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
        deg[u]++, deg[v]++;
    }
    int k = deg[0];
    arr.resize(k);
    vector<int> rad(n + 10, 0);
    vector<vi> vec(k);
    for (int i = 0; i < k; i++) {
        arr[i].pb(0);
        dfs(adj[0][i], 0, i);
        vec[i].assign(arr[i].size() + 10, 0);
    }
    for (int i = 0; i < q; i++) {
        int t, v, x, d;
        cin >> t >> v;
        int j = pos[--v];
        if (t == 0) {
            cin >> x >> d;
            int l = min((int)arr[j].size() + 9, dist[v] + d + 2);
            if (v == 0) {
                add(rad, 1, x);
                add(rad, d + 2, -x);
                continue;
            }
            if (dist[v] <= d) {
                int nd = d - dist[v];
                add(rad, 1, x);
                add(rad, nd + 2, -x);
                add(vec[j], nd + 2, x);
                add(vec[j], l, -x);
                continue;
            }
            add(vec[j], dist[v] - d + 1, x);
            add(vec[j], l, -x);
        } else {
            int ans = get(rad, dist[v] + 1);
            ans += get(vec[j], dist[v] + 1);
            cout << ans << '\n';
        }
    }
}
