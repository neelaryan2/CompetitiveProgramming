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
#define bt(x, b) ((x >> b) & 1LL)
const ll inf = LLONG_MAX;
ll x, y, l, r, ans, pr;
void update(ll k) {
    ll cur = (x & k) * (y & k);
    if (pr > cur) return;
    if (pr < cur) {
        pr = cur;
        ans = k;
        return;
    }
    if (ans > k) {
        ans = k;
    }
}
void solve() {
    int bit = -1;
    pr = -inf, ans = inf;
    ll k, cur, ans1 = 0, ans2 = 0;
    for (int b = 63; b >= 0; b--) {
        cur = (1LL << b);
        if (bt(l, b) != bt(r, b)) {
            ans1 ^= cur;
            bit = b - 1;
            break;
        } else if (bt(l, b)) {
            ans1 ^= cur;
            ans2 ^= cur;
        }
    }
    for (int b = bit; b >= 0; b--) {
        cur = (1LL << b);
        if (!bt(r, b)) continue;
        k = (cur - 1) & (x | y);
        update(k ^ ans1);
        ans1 ^= cur;
    }
    for (int b = bit; b >= 0; b--) {
        cur = (1LL << b);
        if (bt(l, b)) {
            ans2 ^= cur;
            continue;
        }
        k = (cur - 1) & (x | y);
        update(k ^ ans2 ^ cur);
    }
    update(ans1), update(ans2);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cin >> x >> y >> l >> r;
        solve();
        cout << ans << '\n';
    }
}
