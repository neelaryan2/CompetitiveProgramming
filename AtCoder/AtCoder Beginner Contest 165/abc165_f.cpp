/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
vector<int> a, ans;
vector<vi> adj;
set<int> s;
void dfs(int v, int p = -1) {
    auto it = s.lower_bound(a[v]);
    int val = (it != s.end()) ? *it : -1;
    if (it != s.end())
        s.erase(it);
    s.insert(a[v]);
    ans[v] = s.size();
    for (int u : adj[v])
        if (u != p) dfs(u, v);
    s.erase(a[v]);
    if (val != -1) s.insert(val);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    a.resize(n);
    ans.resize(n);
    adj.resize(n);
    for (int& e : a) cin >> e;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0);
    for (int i : ans) cout << i << '\n';
}
