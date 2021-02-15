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

void solve(int test) {
    int n, q, k;
    cin >> n >> q >> k;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = 0;
    a[n + 1] = k + 1;
    vector<int> b(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        b[i] = max(0, a[i + 1] - 1) - (a[i - 1] + 1);
    }
    trace(b);
    for (int i = 1; i <= n; i++)
        b[i] += b[i - 1];
    trace(a);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        int ans;
        if (len == 1) {
            ans = k - 1;
        } else if (len == 2) {
            ans = (a[l + 1] - 2) + (k - a[r - 1] - 1);
        } else {
            ans = (a[l + 1] - 2) + (k - a[r - 1] - 1);
            l++, r--;
            ans += b[r] - b[l - 1];
        }
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << '\n';
    }
}
