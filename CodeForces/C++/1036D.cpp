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

bool is_prime(int n) {
    if (n % 2 == 0)
        return (n == 2);
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

void solve(int test) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll& e : a) cin >> e;
    for (int i = 1; i < n; i++)
        a[i] += a[i - 1];

    int m;
    cin >> m;
    vector<ll> b(m);
    for (ll& e : b) cin >> e;
    for (int i = 1; i < m; i++)
        b[i] += b[i - 1];

    if (a[n - 1] != b[m - 1]) {
        cout << -1;
        return;
    }
    trace(a, b);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int j = lb(all(b), a[i]) - b.begin();
        if (b[j] == a[i]) ans++;
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
