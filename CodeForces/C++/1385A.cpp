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
void solve(int test) {
    int x, y, z;
    cin >> x >> y >> z;
    vector<int> a = {x, y, z};
    sort(all(a));
    x = a[0], y = a[1], z = a[2];
    if (x == y && y == z) {
        cout << "YES\n";
        cout << x << " " << y << " " << z << "\n";
        return;
    }
    if (x == y && y != z) {
        cout << "NO\n";
        return;
    }
    if (y == z) {
        cout << "YES\n";
        cout << 1 << " " << x << " " << z << "\n";
        return;
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
