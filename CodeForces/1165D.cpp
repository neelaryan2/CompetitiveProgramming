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
    int n;
    cin >> n;
    vector<ll> vec(n);
    ll l = 1;
    for (ll& e : vec) {
        cin >> e;
        l = (l * e) / __gcd(l, e);
    }
    sort(all(vec));
    vector<ll> div;
    l = vec[n - 1];
    if (l == vec[n - 1]) l *= vec[0];
    for (ll i = 2; i * i <= l; i++) {
        if (div.size() > n) break;
        if (l % i) continue;
        div.pb(i);
        if (i == l / i) break;
        div.pb(l / i);
    }
    sort(all(div));
    if (div != vec) l = -1;
    cout << l << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
