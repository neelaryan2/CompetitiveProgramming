/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

void solve() {
    ll n, m;
    cin >> n >> m;
    ll k = (n - m) / (m + 1);
    ll z = (n - m) % (m + 1);
    ll ans = (n * (n + 1)) / 2;
    ans -= ((k * (k + 1)) / 2) * (m + 1);
    ans -= (k + 1) * z;
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
