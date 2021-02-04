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
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

ll f(ll n) {
    if (n < 0) return 0;
    return (n * (n + 1)) / 2;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, x, l = 0;
    cin >> n >> x;
    n *= 2;
    vector<ll> d(n);
    for (int i = 0; i < n / 2; i++) {
        int e;
        cin >> e;
        d[i] = d[i + n / 2] = e;
    }
    ll sum = 0, dp = 0, ans = -1;
    trace(d);
    for (int i = 0; i < n; i++) {
        sum += d[i];
        dp += f(d[i]);
        while (l <= i && sum >= x) {
            sum -= d[l];
            dp -= f(d[l]);
            l++;
        }
        int j = l - 1;
        if (l == 0) continue;
        ll extra = d[j] - x + sum;
        trace(l, i, extra);
        ll cur = f(d[j]) - f(extra);
        ans = max(ans, cur + dp);
    }
    cout << ans << '\n';
}
