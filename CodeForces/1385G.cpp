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
vector<int> col, cnt[2];
vector<int> siz, par;
vector<set<int>> adj;
bool bad;
void dfs(int v, int c = 0) {
    col[v] = c;
    cnt[c].eb(v);
    for (int u : adj[v]) {
        if (col[u] != -1) {
            if (col[u] == c) {
                bad = true;
                return;
            }
            continue;
        }
        dfs(u, c ^ 1);
    }
}
void init(int n) {
    adj.assign(n, {});
    col.assign(n, -1);
    par.assign(n, -1);
    siz.assign(n, 1);
    bad = false;
}
int root(int a) {
    if (par[a] == -1) par[a] = a;
    int _a = a;
    while (a != par[a]) a = par[a];
    par[_a] = a;
    return a;
}
void add(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b];
    par[b] = a;
}
void solve(int test) {
    int n;
    cin >> n;
    init(n);
    vector<vector<pii>> pos(n);
    for (int j : {0, 1}) {
        for (int i = 0, e; i < n; i++) {
            cin >> e, e--;
            pos[e].eb(i, j);
        }
    }
    for (int i = 0; i < n; i++) {
        if (pos[i].size() != 2u) {
            cout << "-1\n";
            return;
        }
        pii p1 = pos[i][0], p2 = pos[i][1];
        if (p1.fi == p2.fi) continue;
        if (p1.se != p2.se)
            add(p1.fi, p2.fi);
    }
    vector<vi> comp(n);
    for (int i = 0; i < n; i++) {
        comp[root(i)].eb(i);
        pii p1 = pos[i][0], p2 = pos[i][1];
        if (p1.fi == p2.fi) continue;
        if (p1.se == p2.se) {
            int v = root(p1.fi), u = root(p2.fi);
            if (u == v) {
                cout << "-1\n";
                return;
            }
            adj[u].insert(v);
            adj[v].insert(u);
        }
    }
    vector<int> ans, v;
    for (int i = 0; i < n; i++) {
        if (root(i) != i) continue;
        if (col[i] != -1) continue;
        cnt[0].clear(), cnt[1].clear();
        dfs(i);
        if (bad) {
            cout << "-1\n";
            return;
        }
        int cur1 = 0, cur2 = 0;
        for (int j : cnt[0]) cur1 += siz[j];
        for (int j : cnt[1]) cur2 += siz[j];
        if (cur1 > cur2)
            swap(cnt[0], cnt[1]);
        for (int j : cnt[0])
            for (int t : comp[j])
                ans.eb(t + 1);
    }
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
