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
    int n, m;
    cin >> n >> m;
    vector<int> fac(n+1,1);
    for (int i = 1; i <= n; i++)
        fac[i] = (1LL * fac[i-1] * i) % m;
    int ans = 0, cur;
    for (int d = 0; d < n; d++) {
        cur = (1LL * fac[n - d] * fac[d + 1]) % m;
        cur = (1LL * cur * (n - d)) % m;
        ans = (ans + cur) % m; 
    }
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
