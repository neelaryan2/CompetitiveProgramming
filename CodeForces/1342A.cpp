#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

void solve() {
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    ll ans = 0;
    if (x * y < 0) {
        ans = a * (abs(x) + abs(y));
    } else {
        if (x > y) swap(x, y);
        ans += a * (y - x);
        if (2 * a < b) {
            ans += 2 * a * abs(x);
        } else {
            ans += b * abs(x);
        }
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}