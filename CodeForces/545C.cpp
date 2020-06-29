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
    if (n == 1) {
        cout << "1\n";
        return 0;
    }
    vector<int> x(n), h(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> h[i];
    }
    int ans = 2;
    for (int i = 1; i < n - 1; i++) {
        if (x[i] - h[i] > x[i - 1]) {
            ans++;
        } else if (x[i] + h[i] < x[i + 1]) {
            ans++;
            x[i] += h[i];
        }
    }
    cout << ans << '\n';
}
