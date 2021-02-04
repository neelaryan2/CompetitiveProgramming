/* Author - Neel Aryan (@neelaryan2) */
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
set<int> unvis;
vector<set<int>> adj;
void dfs(int v) {
    vector<int> vec;
    for (int u : unvis) {
        auto it = adj[v].find(u);
        if (it == adj[v].end()) vec.eb(u);
    }
    for (int u : vec) unvis.erase(u);
    for (int u : vec) dfs(u);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for (int i = 0; i < n; i++)
        unvis.insert(i);
    int cnt = 0;
    while (!unvis.empty()) {
        int i = *unvis.begin();
        unvis.erase(i);
        dfs(i), cnt++;
    }
    cout << cnt - 1 << '\n';
}
