#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int inf = INT_MAX;
int level(const pii& a) {
    return max(a.fi, a.se);
}
bool cmp(const pii& a, const pii& b) {
    if (level(a) != level(b)) return level(a) < level(b);
    if (a.fi != b.fi) return a.fi < b.fi;
    return a.se > b.se;
}
ll dist(pii& a, pii& b) {
    return abs(a.fi - b.fi) + abs(a.se - b.se);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pii> pnts(n);
    for (pii& p : pnts) {
        cin >> p.fi >> p.se;
    }
    sort(pnts.begin(), pnts.end(), cmp);
    vector<vector<pii>> lvl(1);
    lvl[0].pb(mp(0, 0));
    int prv = 0;
    for (int i = 0; i < n; i++) {
        if (level(pnts[i]) != prv) {
            lvl.emplace_back();
        }
        lvl.back().pb(pnts[i]);
        prv = level(pnts[i]);
    }
    int l = lvl.size();
    vector<pii> dp(l, mp(0, 0));
    for (int i = 1; i < l; i++) {
        ll must = dist(lvl[i][0], lvl[i].back());
        dp[i].fi = must + min(dp[i - 1].fi + dist(lvl[i - 1][0], lvl[i].back()), dp[i - 1].se + dist(lvl[i - 1].back(), lvl[i].back()));
        dp[i].se = must + min(dp[i - 1].se + dist(lvl[i - 1].back(), lvl[i][0]), dp[i - 1].fi + dist(lvl[i - 1][0], lvl[i][0]));
    }
    ll ans = min(dp.back().fi, dp.back().se);
    cout << ans << endl;
}