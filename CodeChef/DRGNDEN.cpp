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
using vvi = vector<vi>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
vector<int> prevGreater(vector<int>& a) {
    int n = a.size();
    stack<int> s;
    vector<int> ans(n, -1);
    s.push(0);
    for (int i = 1; i < n; i++) {
        while (!s.empty() && a[s.top()] <= a[i])
            s.pop();
        if (!s.empty()) ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> nextGreater(vector<int>& a) {
    int n = a.size();
    stack<int> s;
    vector<int> ans(n, -1);
    s.push(0);
    for (int i = 1; i < n; i++) {
        while (!s.empty() && a[s.top()] < a[i])
            ans[s.top()] = i, s.pop();
        s.push(i);
    }
    return ans;
}
vvi adj[2];
vi tin[2], tout[2];
vector<ll> BIT[2];
int T;
void dfs(int v, int p, int c) {
    tin[c][v] = T++;
    for (int u : adj[c][v])
        dfs(u, v, c);
    tout[c][v] = T++;
}
// check if u is ancestor of v in c-th graph
bool ancestor(int u, int v, int c) {
    return (tin[c][u] <= tin[c][v] && tout[c][v] <= tout[c][u]);
}
void add(vector<ll>& B, int i, int x) {
    int n = B.size();
    for (; i < n; i += i & (-i))
        B[i] = B[i] + x;
}
ll sum(vector<ll>& B, int i) {
    ll sum = 0;
    for (; i > 0; i -= i & (-i))
        sum = sum + B[i];
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    bool inp = true;
    int n, q;
    cin >> n >> q;
    vector<int> h(n), a(n);
    for (int& e : h) cin>>e;
    vector<int> nxt = nextGreater(h);
    vector<int> prv = prevGreater(h);
    vector<int> in[2];
    for (int i : {0, 1}) {
        in[i].assign(n, 0);
        adj[i].resize(n);
        tin[i].resize(n);
        tout[i].resize(n);
    }
    for (int i = 0; i < n; i++) {
        if (nxt[i] != -1) {
            adj[0][nxt[i]].eb(i);
            in[0][i]++;
        }
        if (prv[i] != -1) {
            adj[1][prv[i]].eb(i);
            in[1][i]++;
        }
    }
    for (int j : {0, 1}) {
        T = 1;
        for (int i = 0; i < n; i++) {
            if (in[j][i]) continue;
            dfs(i, -1, j);
        }
        BIT[j].assign(T, 0);
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j : {0, 1}) {
            add(BIT[j], tin[j][i], a[i]);
            add(BIT[j], tout[j][i], -a[i]);
        }
    }
    for (int _ = 0; _ < q; _++) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            int delta = y - a[--x];
            a[x] = y;
            for (int j : {0, 1}) {
                add(BIT[j], tin[j][x], delta);
                add(BIT[j], tout[j][x], -delta);
            }
        }
        if (t == 2) {
            x--, y--;
            int j = (x < y);
            if (!ancestor(x, y, j)) {
                cout << "-1\n";
                continue;
            }
            ll ans = sum(BIT[j], tin[j][y]);
            ans -= sum(BIT[j], tin[j][x]);
            cout << ans + a[x] << '\n';
        }
    }
}
