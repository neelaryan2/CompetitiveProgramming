#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

void solve() {
    ll n;
    cin >> n;
    int ans = 0;
    while (n) {
        ld cur = sqrtl(24 * n + 1);
        cur = (cur - 1) / 6;
        ll tmp = cur;
        if (!tmp) break;
        n -= (tmp * (3 * tmp + 1)) / 2;
        ans++;
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
