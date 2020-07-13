#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using ld = long double;
using pii = pair<ll, int>;
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
    int n;
    cin >> n;
    vector<ll> a(n), pref(n), suf(n);
    for (ll& e : a) cin >> e;
    if (n == 1) {
        cout << a[0] << '\n';
        return;
    }
    pref[0] = a[0];
    pref[1] = a[1];
    for (int i = 2; i < n; i++)
        pref[i] = pref[i - 2] + a[i];
    suf[n - 1] = a[n - 1];
    suf[n - 2] = a[n - 2];
    for (int i = n - 3; i >= 0; i--)
        suf[i] = suf[i + 2] + a[i];
    assert(pref[n - 1] == suf[0]);
    ll ans = suf[0];
    for (int i = 1; i < n; i++)
        ans = max(ans, pref[i - 1] + suf[i]);
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
