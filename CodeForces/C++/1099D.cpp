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
vector<int> s, a;
vector<vi> adj;
void dfs(int v, int h = 1, int p = -1) {
    if (h % 2 == 0 && adj[v].empty()) {
        s[v] = s[p];
        a[v] = 0;
        return;
    }
    if (h % 2 == 0) {
        set<int> st;
        for (int u : adj[v])
            st.insert(s[u]);
        s[v] = *st.begin();
        a[v] = s[v] - s[p];
        if (a[v] < 0) {
            cout << "-1\n";
            exit(0);
        }
    }
    a[v] = s[v];
    if (p != -1) a[v] -= s[p];
    for (int u : adj[v])
        dfs(u, h + 1, v);
}
void solve(int test) {
    int n;
    cin >> n;
    adj.resize(n);
    s.resize(n);
    a.assign(n, 0);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p, p--;
        adj[p].eb(i);
    }
    for (int& e : s) cin >> e;
    a[0] = s[0];
    dfs(0);
    ll sum = 0;
    for (int& e : a) sum += e;
    cout << sum;
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
        cout << "\n";
    }
}
