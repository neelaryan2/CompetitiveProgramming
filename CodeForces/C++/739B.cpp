/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using ld = long double;
using pii = pair<ll, ll>;
using vi = vector<int>;
using ppi = pair<pii, ll>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
vector<vector<pii>> adj;
vector<int> ans, a;
set<ppi> s;
void dfs(int v, ll d, int dep = 0) {
    ppi t = mp(mp(d - a[v], -1), -1);
    auto it = s.lb(t);
    if (it != s.end())
        ans[it->se]--, ans[v]++;
    t = mp(mp(d, dep), v);
    s.insert(t);
    for (pii p : adj[v])
        dfs(p.fi, d + p.se, dep + 1);
    s.erase(t);
}
int dfs2(int v) {
    int pref = ans[v];
    ans[v] = 0;
    for (pii p : adj[v])
        ans[v] += dfs2(p.fi);
    return ans[v] + pref;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    a.resize(n);
    adj.resize(n);
    ans.assign(n, 0);
    for (int& e : a) cin >> e;
    for (int i = 1, p, w; i < n; i++) {
        cin >> p >> w, p--;
        adj[p].pb(mp(i, w));
    }
    dfs(0, 0);
    trace(ans);
    dfs2(0);
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';
}
