#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using pii = pair<ll, ll>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const int p1 = 1e9 + 7, p2 = 23333;
pii vec_hash(const vector<int>& vec) {
    pii p = {0, 0};
    ll pw1 = 1, pw2 = 1;
    for (int i : vec) {
        p.fi = p.fi + (pw1 * (i + 2000017));
        p.se = p.se + (pw2 * (i + 2000017));
        pw1 = pw1 * p1;
        pw2 = pw2 * p2;
    }
    return p;
}
ll calc(vector<vi>& adj) {
    map<pii, int> cnt;
    ll ret = 0;
    int n = adj.size();
    for (int i = 0; i < n; i++) {
        pii hs = vec_hash(adj[i]);
        auto it = cnt.find(hs);
        if (it != cnt.end()) {
            ret += it->se;
            it->se++;
        } else
            cnt[hs] = 1;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vi> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 0; i < n; i++) {
        sort(all(adj[i]));
    }
    ll ans = calc(adj);
    // cout << ans << '\n';
    for (int i = 0; i < n; i++) {
        adj[i].pb(i);
        sort(all(adj[i]));
    }
    ans += calc(adj);
    cout << ans << '\n';
}
