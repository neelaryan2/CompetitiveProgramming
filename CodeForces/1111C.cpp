/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using pii = pair<ll, int>;
using vi = vector<int>;
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
ll n, k, A, B;
vector<int> pos;
ll solve(ll s, ll e) {
    int cnt = lb(all(pos), e) - lb(all(pos), s);
    if (cnt == 0) return A;
    if (s == e - 1) return cnt * B;
    ll m = (s + e) / 2;
    ll lef = solve(s, m);
    ll righ = solve(m, e);
    ll cost = B * cnt * (e - s);
    cost = min(cost, lef + righ);
    return cost;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k >> A >> B;
    pos.resize(k);
    for (int& e : pos) cin >> e, e--;
    sort(all(pos));
    ll ans = solve(0, 1 << n);
    cout << ans << '\n';
}
