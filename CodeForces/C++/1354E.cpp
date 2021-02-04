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
using vb = vector<bool>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
vector<vi> adj;
vector<vector<vi>> sep;
vector<int> vis, comp, col;
int T, bad;
void dfs(int v, int c = 0) {
    comp[v] = T;
    col[v] = c;
    sep[c][T].pb(v);
    vis[v] = true;
    for (int u : adj[v]) {
        if (vis[u]) {
            if (col[u] == c) bad = 1;
            continue;
        }
        dfs(u, 1 - c);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    T = 0;
    vis.assign(n, false);
    comp.assign(n, -1);
    col.assign(n, -1);
    sep.resize(2);
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        sep[0].emplace_back();
        sep[1].emplace_back();
        bad = 0;
        dfs(i);
        T++;
        if (bad) {
            cout << "NO" << '\n';
            return 0;
        }
    }
    vector<int> ans(n);
    vector<vb> dp(T + 1, vb(n + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= T; i++) {
        for (int j = 0; j <= n; j++) {
            int a = i ? sep[0][i - 1].size() : 0;
            int b = i ? sep[1][i - 1].size() : 0;
            trace(i, j);
            if (j >= a && dp[i - 1][j - a])
                dp[i][j] = true;
            if (j >= b && dp[i - 1][j - b])
                dp[i][j] = true;
        }
    }
    if (!dp[T][n2]) {
        cout << "NO" << '\n';
        return 0;
    }
    vector<int> sz;
    for (int i = T; i >= 1; i--) {
        int a = sep[0][i - 1].size();
        int b = sep[1][i - 1].size();
        if (n2 >= a && dp[i - 1][n2 - a])
            sz.pb(a);
        else if (n2 >= b && dp[i - 1][n2 - b])
            sz.pb(b);
        else {
            cout << "NO" << '\n';
            return 0;
        }
        n2 -= sz.back();
    }
    trace(adj);
    reverse(all(sz));
    for (int i = 0; i < T; i++) {
        int a = sep[0][i].size();
        int b = sep[1][i].size();
        if (sz[i] == a) {
            for (int v : sep[0][i])
                ans[v] = 2;
            for (int v : sep[1][i]) {
                if (n1 != 0)
                    ans[v] = 1, n1--;
                else if (n3 != 0)
                    ans[v] = 3, n3--;
                else {
                    cout << "NO" << '\n';
                    return 0;
                }
            }
        } else {
            for (int v : sep[1][i])
                ans[v] = 2;
            for (int v : sep[0][i]) {
                if (n1 != 0)
                    ans[v] = 1, n1--;
                else if (n3 != 0)
                    ans[v] = 3, n3--;
                else {
                    cout << "NO" << '\n';
                    return 0;
                }
            }
        }
    }
    cout<<"YES\n";
    for (int i : ans) cout << i;
    cout << '\n';
}
