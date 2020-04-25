#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const ll inf = 1e18;

vector<vector<ll>> dist;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int& e : a) cin >> e;
    int g, r;
    cin >> g >> r;
    dist.assign(m, vector<ll>(g + 1, inf));
    sort(all(a));
    deque<pii> q;
    q.push_back({0, 0});
    dist[0][0] = 0;
    while (!q.empty()) {
        ll v = q.front().fi;
        ll t = q.front().se;
        q.pop_front();
        ll offset = t, extra = 0;
        ll nt, nd, diff;
        if (t == g) {
            offset = 0;
            extra = r;
        }
        for (int u : {v - 1, v + 1}) {
            if (u < 0 || u >= m) continue;
            diff = abs(a[v] - a[u]);
            nt = diff + offset;
            nd = dist[v][t] + diff + extra;
            if (nt <= g && dist[u][nt] > nd) {
                dist[u][nt] = nd;
                if (t == g)
                    q.push_back({u, nt});
                else
                    q.push_front({u, nt});
            }
        }
    }
    ll ans = inf;
    for (int i = 0; i <= g; i++) {
        ans = min(ans, dist[m - 1][i]);
    }
    cout << (ans == inf ? -1 : ans) << endl;
}