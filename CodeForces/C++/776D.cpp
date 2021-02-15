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

vector<vector<int>> adj, radj;
vector<bool> used, assignment;
vector<int> order, comp;
int neg(int v) {
    int n = adj.size() / 2;
    return (v < n ? v + n : v - n);
}
void add(int p, int q) {
    int np = neg(p), nq = neg(q);
    adj[p].emplace_back(q);
    adj[nq].emplace_back(np);
    radj[q].emplace_back(p);
    radj[np].emplace_back(nq);
}
void dfs1(int v) {
    used[v] = true;
    for (int u : adj[v]) {
        if (!used[u])
            dfs1(u);
    }
    order.emplace_back(v);
}
void dfs2(int v, int cl) {
    comp[v] = cl;
    for (int u : radj[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}
bool solve_2SAT() {
    int n = adj.size();
    order.clear();
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs1(i);
    }
    comp.assign(n, -1);
    for (int i = n - 1, j = 0; i >= 0; i--) {
        int v = order[i];
        if (comp[v] == -1)
            dfs2(v, j++);
    }
    int k = n / 2;
    assignment.assign(k, false);
    for (int i = 0; i < k; i++) {
        if (comp[i] == comp[i + k])
            return false;
        assignment[i] = (comp[i] > comp[i + k]);
    }
    return true;
}

void solve(int test) {
    int n, m;
    cin >> n >> m;
    vector<int> r(n);
    vector<vi> switches(n);
    for (int& e : r) cin >> e;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int e;
            cin >> e;
            switches[--e].eb(i);
        }
    }
    adj.assign(2 * m, {});
    radj.assign(2 * m, {});
    for (int i = 0; i < n; i++) {
        assert(switches[i].size() == 2);
        int p = switches[i][0];
        int q = switches[i][1];
        if (r[i]) {
            add(p, q);
            add(q, p);
        } else {
            add(neg(p), q);
            add(q, neg(p));
        }
    }
    cout << (solve_2SAT() ? "YES" : "NO");
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
