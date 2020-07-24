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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0;
    for (int& e : a) {
        cin >> e;
        if (e == 1) cnt++;
    }
    if (cnt > 0) {
        cout << n - cnt << '\n';
        return 0;
    }
    int ans = n + 1;
    for (int i = 0; i < n; i++) {
        int g = 0;
        for (int j = i; j < n; j++) {
            g = __gcd(g, a[j]);
            if (g == 1) {
                ans = min(ans, j - i);
                break;
            }
        }
    }
    ans += n - 1;
    if (ans == 2 * n) ans = -1;
    cout << ans << '\n';
}
