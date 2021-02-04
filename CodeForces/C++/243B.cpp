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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, h, t;
    cin >> n >> m >> h >> t;
    vector<set<int>> adj(n);
    vector<int> deg(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].insert(v);
        adj[v].insert(u);
        deg[v]++, deg[u]++;
    }
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        vis[i] = true;
        if (deg[i] <= min(h, t)) continue;
        for (int j : adj[i]) {
            if (vis[j]) continue;
            if (deg[j] <= min(h, t)) continue;
            if (deg[i] >= t + h + 1 && deg[j] >= h + t + 1) {
                adj[i].erase(j);
                adj[j].erase(i);
                cout << "YES\n";
                cout << i + 1 << ' ' << j + 1 << '\n';
                vector<bool> done(n, false);
                for (int v : adj[i]) {
                    if (h == 0) break;
                    cout << v + 1 << ' ';
                    done[v] = true, h--;
                }
                cout << '\n';
                for (int v : adj[j]) {
                    if (t == 0) break;
                    if (done[v]) continue;
                    cout << v + 1 << ' ';
                    done[v] = true, t--;
                }
                cout << '\n';
                return 0;
            }
            int c1 = i, c2 = j, k = 0;
            vector<int> vec;
            if (deg[c1] > deg[c2]) swap(c1, c2);
            for (int v : adj[c1]) {
                auto it = adj[c2].find(v);
                if (it != adj[c2].end()) vec.pb(*it);
            }
            k = vec.size();
            int n1 = max(min(h, t) + k + 1 - deg[c1], 0);
            int n2 = max(max(h, t) + k + 1 - deg[c2], 0);
            if (n1 + n2 > k) continue;
            if (h > t) swap(c1, c2);
            adj[c1].erase(c2);
            adj[c2].erase(c1);
            trace(adj[c1], n1);
            trace(adj[c2], n2);
            cout << "YES\n";
            cout << c1 + 1 << ' ' << c2 + 1 << '\n';
            vi hans, tans;
            for (int z = 0; z < n1; z++) {
                hans.pb(vec.back() + 1);
                adj[c1].erase(vec.back());
                adj[c2].erase(vec.back());
                h--, vec.pop_back();
            }
            for (int z = 0; z < n2; z++) {
                tans.pb(vec.back() + 1);
                adj[c1].erase(vec.back());
                adj[c2].erase(vec.back());
                t--, vec.pop_back();
            }
            for (int v : adj[c1]) {
                if (h == 0) break;
                hans.pb(v + 1);
                adj[c2].erase(v);
                h--;
            }
            for (int v : adj[c2]) {
                if (t == 0) break;
                tans.pb(v + 1);
                t--;
            }
            for (int i : hans) cout << i << ' ';
            cout << '\n';
            for (int i : tans) cout << i << ' ';
            cout << '\n';
            return 0;
        }
    }
    cout << "NO\n";
}
