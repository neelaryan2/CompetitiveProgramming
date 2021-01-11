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
ll x, ans;
map<ll, ll> memo;

ll solve(ll y) {
    auto it = memo.find(y);
    if (it != memo.end()) return it->se;
    ll v = abs(y - x);
    if (y <= 1) return v;
    if (y % 2)
        v = min(v, 2 + min(solve((y + 1) / 2), solve((y - 1) / 2)));
    else
        v = min(v, 1 + solve(y / 2));
    return memo[y] = v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll y; cin >> x >> y;
    if (x >= y) 
        ans = x - y;
    else
        ans = solve(y);
    cout << ans << endl;
}
