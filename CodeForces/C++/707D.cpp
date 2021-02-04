#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ppi = pair<int, pii>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
int n, m, q, x, y;
vector<ppi> que;
vector<int> ans;
vector<vi> adj;
vector<bitset<1001>> sh;
bitset<1001> ones;
int cnt = 0;
void dfs(int v) {
    ans[v] = cnt;
    for (int u : adj[v]) {
        ppi q = que[u];
        int t = q.fi;
        int i = q.se.fi;
        int j = q.se.se;
        if (t == 1) {
            if (sh[i][j]) {
                dfs(u);
            } else {
                sh[i][j] = 1;
                cnt++;
                dfs(u);
                cnt--;
                sh[i][j] = 0;
            }
        } else if (t == 2) {
            if (!sh[i][j]) {
                dfs(u);
            } else {
                sh[i][j] = 0;
                cnt--;
                dfs(u);
                cnt++;
                sh[i][j] = 1;
            }
        } else if (t == 3) {
            int was = sh[i].count();
            sh[i] ^= ones;
            int now = sh[i].count();
            cnt += now - was;
            dfs(u);
            cnt += was - now;
            sh[i] ^= ones;
        } else {
            dfs(u);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> q;
    adj.resize(q + 1);
    sh.resize(n);
    que.resize(q + 1);
    ans.resize(q + 1);
    for (int i = 0; i < m; i++)
        ones[i] = 1;
    int cur = 0;
    for (int i = 1; i <= q; i++) {
        int t;
        cin >> t;
        if (t <= 2) {
            cin >> x >> y;
            adj[cur].pb(i);
            que[i] = {t, {--x, --y}};
        } else if (t == 3) {
            cin >> x;
            adj[cur].pb(i);
            que[i] = {t, {--x, -1}};
        } else {
            cin >> x;
            adj[x].pb(i);
            que[i] = {t, {x, -1}};
        }
        cur = i;
    }
    dfs(0);
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}
