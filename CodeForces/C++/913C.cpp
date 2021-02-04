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
const int N = 31;
const ll inf = 1e18;
void solve(int test) {
    int n, L;
    cin >> n >> L;
    vector<ll> c(N, inf);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 1; i < N; i++)
        c[i] = min(c[i], 2 * c[i - 1]);
    trace(c);
    ll sofar = 0, ans = inf;
    for (int i = N - 1; i >= 0; i--) {
        if ((L >> i) & 1) {
            sofar += c[i];
        } else {
            ans = min(ans, sofar + c[i]);
        }
    }
    ans = min(ans, sofar);
    cout << ans;
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
