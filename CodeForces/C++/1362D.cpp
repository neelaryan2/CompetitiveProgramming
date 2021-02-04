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
void NO() {
    cout << "-1\n";
    exit(0);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vi> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<set<int>> done(n);
    vector<int> ord(n), t(n);
    iota(all(ord), 0);
    for (int& e : t) cin >> e;
    sort(all(ord), [&](int a, int b) {
        return t[a] < t[b];
    });
    for (int i : ord) {
        auto it = done[i].find(t[i]);
        if (it != done[i].end()) NO();
        if (done[i].size() != t[i] - 1) NO();
        for (int j : adj[i])
            done[j].insert(t[i]);
    }
    for (int i : ord) cout << i + 1 << ' ';
    cout << '\n';
}
