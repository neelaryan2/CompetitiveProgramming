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

ld exp(ld n, int k) {
    if (n == 0) return 0;
    ld r = 1;
    while (k) {
        if (k & 1) r = r * n;
        k >>= 1, n = n * n;
    }
    return r;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m, n;
    cin >> m >> n;
    ld sm = 0;
    for (int i = 0; i < m; i++) {
        ld cur = (ld)i / m;
        sm += exp(cur, n);
    }
    cout << fixed << setprecision(12) << m - sm << '\n';
}
