#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ppi = pair<pii, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
vector<pii> pnts, con;
vector<ppi> c;
vector<int> vec, k;
ll get(int x, int y) {
    ll dist = abs(pnts[x].fi - pnts[y].fi);
    dist += abs(pnts[x].se - pnts[y].se);
    dist *= k[x] + k[y];
    return dist;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    pnts.resize(n);
    c.resize(n);
    k.resize(n);
    for (pii& p : pnts) cin >> p.fi >> p.se;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        c[i] = {{e, -1}, i};
    }
    for (int& e : k) cin >> e;
    sort(all(c));
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ppi p = c[i];
        ans += p.fi.fi;
        if (p.fi.se == -1)
            vec.pb(p.se);
        else
            con.pb({p.se, p.fi.se});
        for (int j = i + 1; j < n; j++) {
            ppi& q = c[j];
            ll tmp = get(q.se, p.se);
            if (q.fi.fi > tmp) {
                q.fi.fi = tmp;
                q.fi.se = p.se;
            }
        }
        sort(c.begin() + i + 1, c.end());
    }
    sort(all(vec));
    cout << ans << '\n';
    cout << vec.size() << '\n';
    for (int i : vec) cout << ++i << ' ';
    cout << '\n';
    cout << con.size() << '\n';
    for (pii& p : con) {
        if (p.fi > p.se) swap(p.fi, p.se);
        cout << ++p.fi << ' ' << ++p.se << '\n';
    }
}
