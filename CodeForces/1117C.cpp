#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define N 1e18
int main() {
    ll x1, y1, x2, y2, n;
    string wind;
    cin >> x1 >> y1 >> x2 >> y2 >> n >> wind;
    pair<ll, ll> dp[n + 1];
    dp[0] = make_pair(0, 0);
    for (ll i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if (wind[i - 1] == 'U') dp[i].s++;
        if (wind[i - 1] == 'D') dp[i].s--;
        if (wind[i - 1] == 'R') dp[i].f++;
        if (wind[i - 1] == 'L') dp[i].f--;
    }
    ll mid, hi = N, lo = 1;
    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        ll x = (mid / n) * dp[n].f + dp[mid % n].f;
        ll y = (mid / n) * dp[n].s + dp[mid % n].s;
        x += x1; y += y1;
        x = abs(x2 - x); y = abs(y2 - y);
        if (x + y > mid) lo = mid + 1;
        else hi = mid;
    }
    if (lo >= N || lo < 0)
        cout << -1 << endl;
    else cout << lo << endl;
}