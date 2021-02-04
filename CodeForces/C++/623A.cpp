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

vector<set<int>> adj;
string s;
void dfs(int v) {
    s[v] = 'a';
    for (int u : adj[v])
        if (s[u] == 'd')
            dfs(u);
}
void solve(int test) {
    int n, m;
    cin >> n >> m;
    adj.assign(n, {});
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    s.assign(n, 'd');
    for (int i = 0; i < n; i++)
        if (adj[i].size() == n - 1)
            s[i] = 'b';
    for (int i = 0; i < n; i++) {
        if (s[i] == 'd') {
            dfs(i);
            break;
        }
    }
    for (int i = 0; i < n; i++)
        if (s[i] == 'd')
            s[i] = 'c';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (abs(s[i] - s[j]) <= 1) {
                auto it = adj[i].find(j);
                if (it == adj[i].end()) {
                    cout << "No";
                    return;
                }
            }
        }
    }
    cout << "Yes\n";
    cout << s;
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