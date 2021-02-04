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
    ll n;
    cin >> n;
    vector<ll> div;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i) continue;
        while (n % i == 0) n /= i;
        div.eb(i);
    }
    if (n > 1) div.eb(n);
    ll ans = 1;
    if (div.size() == 1) ans = div[0];
    cout << ans << '\n';
}
