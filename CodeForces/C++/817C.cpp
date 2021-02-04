#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, s;
bool check(ll t) {
    ll c = t, sum = 0;
    while (c) {
        sum += c % 10, c /= 10;
    }
    c = t - sum;
    return c >= s;
}
int main() {
    cin >> n >> s;
    ll lo = 1, hi = 2e18, mid;
    while (lo < hi - 1) {
        mid = lo + (hi - lo) / 2;
        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }
    cout << max(0LL, n - hi + 1) << endl;
}