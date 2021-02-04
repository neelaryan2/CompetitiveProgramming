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
void solve(int test) {
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    ll sum = a[0], ans = 0;
    vector<ll> p(n, a[0]);
    for (int i = 1; i < n; i++)
        p[i] = p[i - 1] + a[i];
    for (int i = 1; i <= k; i++) {
        int moves = k - i, zz = z;
        int left = min(z, moves / 2);
        moves -= 2 * left, zz -= left;
        // trace(left, moves, zz);
        ll cur = 1LL * left * (a[i] + a[i - 1]);
        cur += p[i + moves];
        if (moves == 1 && zz)
            cur += max(a[i - 1] - a[i + 1], 0);
        trace(moves, left, cur);
        ans = max(ans, cur);
    }
    cout << ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << "\n";
    }
}
