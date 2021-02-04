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
void solve(int test) {
    int n, k;
    cin >> n >> k;
    vector<vi> adj(n);
    vector<int> deg(n, 0);
    vector<bool> leaf(n, false);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].eb(v);
        adj[v].eb(u);
        deg[u]++, deg[v]++;
    }
    if (n == 2 && k == 1) {
        cout << "1\n";
        return;
    }
    for (int i = 0; i < n; i++)
        if (deg[i] == 1) leaf[i] = true;
    set<pii> s, st;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j : adj[i])
            if (leaf[j]) cnt++;
        s.insert(mp(cnt, i));
        st.insert(mp(i, cnt));
    }
    int ans = 0;
    while (true) {
        auto it = s.lb(mp(k, -1));
        if (it == s.end()) break;
        ans++;
        pii p = *it;
        s.erase(p);
        st.erase(mp(p.se, p.fi));
        int v = p.se, cnt = p.fi, t = deg[v];
        if (cnt > k || t - k != 1) {
            deg[v] -= k;
            s.insert(mp(cnt - k, v));
            st.insert(mp(v, cnt - k));
            continue;
        }
        leaf[v] = true;
        for (int u : adj[v]) {
            if (leaf[u]) continue;
            auto it2 = st.lb(mp(u, -1));
            p = *it2;
            st.erase(it2);
            swap(p.fi, p.se);
            it = s.lb(p);
            p = *it;
            s.erase(it);
            p.fi++;
            s.insert(p);
            st.insert(mp(p.se, p.fi));
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
