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
pii get(ll b) {
    ll mn = 11, mx = -1;
    while (b) {
        mn = min(mn, b % 10);
        mx = max(mx, b % 10);
        b /= 10;
    }
    return mp(mn, mx);
}
void solve() {
    ll a, k;
    cin >> a >> k;
    while (k > 1) {
        pii p = get(a);
        if (p.fi == 0) break;
        a += p.fi * p.se;
        k--;
    }
    cout << a << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
