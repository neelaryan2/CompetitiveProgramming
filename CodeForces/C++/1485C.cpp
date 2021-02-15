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

ll getSum(int n) {
    ll sum = 0;
    int k = sqrtl(n);
    for (int i = 1; i <= k; i++) {
        sum += floor(n / i);
    }
    sum *= 2;
    sum -= pow(k, 2);
    return sum;
}

void solve(int test) {
    ll x, y;
    cin >> x >> y;
    y = min(y, x - 1);
    ll b = 2, ans = 0;
    for (; b <= y && b * b + b <= x; b++)
        ans += b - 1;
    ll l, r;
    auto get = [&](int k) {
        l = 1 + x / (k + 1);
        r = x / k;
    };
    for (ll i = x / (y + 1); i <= x / (b + 1); i++) {
        get(i);
        ll cnt = min(r, y + 1) - max(l, b + 1) + 1;
        ans += cnt * i;
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
        cout << '\n';
    }
}
