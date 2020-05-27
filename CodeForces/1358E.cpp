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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    ll sum = 0;
    for (int i = 0; i < n - n / 2; i++) {
        cin >> a[i];
        sum += a[i];
    }
    ll x;
    cin >> x;
    for (int i = n - n / 2; i < n; i++) {
        a[i] = x;
        sum += x;
    }
    if (x >= 0) {
        if (sum <= 0) n = -1;
        cout << n << '\n';
        return 0;
    }
    vector<ll> p(n + 1, 0);
    for (int i = 0; i < n; i++) {
        p[i + 1] = p[i] + a[i];
    }
    trace(a, p);
    ll mx = -1e18;
    for (int i = 0; i <= n / 2; i++) {
        mx = max(mx, p[i] + x * (n - i));
        if (mx < sum + x * (n - i)) {
            cout << n - i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}
