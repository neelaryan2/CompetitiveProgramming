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
    ll l, r, k;
    cin >> l >> r >> k;
    ll p = 1;
    int cnt = 0;
    while (p <= r) {
        if (p >= l) {
            cout << p << ' ';
            cnt++;
        }
        if (p >= LLONG_MAX / k) break;
        p *= k;
    }
    if (cnt == 0) cout << -1;
    cout << '\n';
}
