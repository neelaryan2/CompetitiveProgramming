#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ppi = pair<int, pii>;
using vi = vector<int>;
using vpi = vector<pii>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
vector<int> par, tin, tout, doc, ans;
vector<vi> adj;
vector<vpi> docq;
vector<ppi> q;
vector<bool> is;
int T = 0;
void dfs(int v) {
    tin[v] = T++;
    for (int u : adj[v])
        dfs(u);
    tout[v] = T++;
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
    if (a > b) swap(a, b);
    par[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    q.resize(m);
    is.assign(n, true);
    adj.resize(n);
    tin.resize(n);
    tout.resize(n);
    ans.assign(m, -1);
    par.assign(n, -1);
    for (ppi& p : q) {
        cin >> p.fi >> p.se.fi;
        if (p.fi != 2)
            cin >> p.se.se;
        else
            p.se.se = 0;
        p.se.fi--;
        p.se.se--;
        if (p.fi == 1) {
            adj[p.se.se].pb(p.se.fi);
            is[p.se.fi] = false;
        }
        if (p.fi == 2) {
            doc.pb(p.se.fi);
        }
    }
    docq.resize(doc.size());
    for (int i = 0; i < m; i++) {
        ppi p = q[i];
        if (p.fi == 3)
            docq[p.se.se].pb({p.se.fi, i});
    }
    for (int i = 0; i < n; i++) {
        if (is[i]) dfs(i);
    }
    int num = 0;
    for (ppi& p : q) {
        if (p.fi == 1) {
            add(p.se.fi, p.se.se);
        } else if (p.fi == 2) {
            int cur = num++;
            int x = doc[cur];
            for (pii& p : docq[cur]) {
                int y = p.fi;
                if (root(x) != root(y))
                    ans[p.se] = 0;
                else {
                    if (tin[y] <= tin[x] && tout[x] <= tout[y])
                        ans[p.se] = 1;
                    else
                        ans[p.se] = 0;
                }
            }
        }
    }
    for (int i : ans) {
        if (i == -1) continue;
        if (i)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}