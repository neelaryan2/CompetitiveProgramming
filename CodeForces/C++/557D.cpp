#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ppi = pair<pii, int>;
using vpi = vector<pii>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define runtime() (int)(1000 * ((double)clock()) / CLOCKS_PER_SEC)
using vi = vector<int>;
vector<vi> adj;
vi vis, col, cnt(2, 0);
bool cyc = false, odd = false;
void dfs(int v, int c = 0) {
    vis[v] = 1;
    col[v] = c;
    cnt[c]++;
    for (int u : adj[v]) {
        if (vis[u] == 2) continue;
        if (vis[u] == 1) {
            cyc = true;
            if (col[u] == col[v]) odd = true;
        } else
            dfs(u, 1 - c);
    }
    vis[v] = 2;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, mx = -1;
    cin >> n >> m;
    adj.resize(n);
    vis.assign(n, 0);
    col.assign(n, -1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int cnt1 = 0, cnt2 = 0;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        cnt[0] = cnt[1] = 0;
        dfs(i);
        int tot = cnt[0] + cnt[1];
        mx = max(mx, tot);
        if (tot == 1)
            cnt1++;
        else if (tot == 2)
            cnt2++;
        res += (1LL * cnt[0] * (cnt[0] - 1)) / 2;
        res += (1LL * cnt[1] * (cnt[1] - 1)) / 2;
    }
    if (odd) {
        cout << "0 1\n";
        return 0;
    }
    if (mx == 1) {
        cout << "3 ";
        res = (1LL * n * (n - 1)) / 2;
        res = (res * (n - 2)) / 3;
        cout << res << '\n';
        return 0;
    }
    if (mx == 2) {
        cout << "2 ";
        res = 2LL * cnt2 * (cnt2 - 1);
        res += 1LL * cnt1 * cnt2;
        cout << res << '\n';
        return 0;
    }
    cout << "1 ";
    cout << res << '\n';
}