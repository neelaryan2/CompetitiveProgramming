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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x, y, n;
    cin >> x >> y >> n;
    ll a, b;
    ld ref = ((ld)x) / y;
    ld ans = 1e18;
    for (int i = 1; i <= n; i++) {
        ll k = 1LL * i * x;
        if (k % y == 0) {
            cout << k / y << '/' << i << '\n';
            return 0;
        }
        k /= y;
        ld k1 = ((ld)k) / i;
        ld k2 = ((ld)(k + 1)) / i;
        if (abs(k1 - ref) < abs(ans - ref)) {
            a = k, b = i;
            ans = k1;
        }
        if (abs(k2 - ref) < abs(ans - ref)) {
            a = k + 1, b = i;
            ans = k2;
        }
    }
    cout << a << '/' << b << '\n';
}
