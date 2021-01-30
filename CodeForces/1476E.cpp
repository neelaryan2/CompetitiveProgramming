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
#define rall(v) (v).rbegin(), (v).rend()

const int inf = 1e9 + 7;

vector<vi> adj;
vector<int> vis, ans;
bool bad;

void dfs(int v) {
    vis[v] = 1;
    for (int u : adj[v]) {
        if (vis[u]) {
            if (vis[u] == 1) {
                bad = true;
            }
        } else
            dfs(u);
    }
    vis[v] = 2;
    ans.eb(v + 1);
}

void topological_sort() {
    int n = adj.size();
    vis.assign(n, 0);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!vis[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

void solve(int test) {
    int n, m, k;
    cin >> n >> m >> k;
    map<string, int> mem;
    vector<string> vec(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mem[s] = i;
        vec[i] = s;
    }
    vector<int> mt(m);
    vector<string> st(m);
    for (int i = 0; i < m; i++) {
        cin >> st[i] >> mt[i];
        mt[i]--;
        for (int j = 0; j < k; j++) {
            char c = vec[mt[i]][j];
            if (c == '_') continue;
            if (c != st[i][j]) {
                cout << "NO";
                return;
            }
        }
    }
    adj.assign(n, {});
    for (int i = 0; i < m; i++) {
        trace(st[i]);
        for (int j = 0; j < (1 << k); j++) {
            string cur = st[i];
            for (int b = 0; b < k; b++)
                if ((j >> b) & 1) cur[b] = '_';
            trace(cur);
            auto it = mem.find(cur);
            if (it == mem.end()) continue;
            if (it->se != mt[i])
                adj[mt[i]].eb(it->se);
        }
    }
    trace(adj);
    bad = false;
    topological_sort();
    if (bad) {
        cout << "NO";
    } else {
        cout << "YES\n";
        for (int i : ans)
            cout << i << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << '\n';
    }
}
