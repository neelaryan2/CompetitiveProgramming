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

void solve(int test) {
    int x;
    cin >> x;
    if (x == 0) {
        cout << "1 1";
        return;
    }
    int n, y, lo, hi;
    for (int i = 1; i * i <= x; i++) {
        int a = i, b = x / i;
        if (b > a) swap(a, b);
        if (x % i) continue;
        if ((a + b) % 2) continue;
        n = (a + b) / 2, y = (a - b) / 2;
        if (y == 0) continue;
        lo = 1 + n / (y + 1), hi = n / y;
        if (lo > hi) continue;
        cout << n << ' ' << hi;
        return;
    }
    cout << -1;
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
