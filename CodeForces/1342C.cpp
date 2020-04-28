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
ll a, b, l;
ll get(ll num, int j) {
    num -= j;
    ll ret = num / b - num / l;
    return ret;
}
void solve() {
    int q;
    cin >> a >> b >> q;
    if (a > b) swap(a, b);
    l = (a * b) / __gcd(a, b);
    for (int i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        ll ans = 0;
        for (int j = 0; j < b; j++) {
            ans += get(r, j) - get(l - 1, j);
        }
        cout << ans << ' ';
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}