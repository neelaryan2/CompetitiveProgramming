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

bool solve(int test) {
    ll a, b, n, m;
    cin >> a >> b >> n >> m;
    if (a > b) swap(a, b);
    ll t = min(b - a, n);
    b -= t, n -= t;
    ll mn = min({a, n, m});
    a -= mn, b -= mn;
    n -= mn, m -= mn;
    if (n) a += b;
    return a >= m + n;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        puts(solve(i) ? "Yes" : "No");
    }
}