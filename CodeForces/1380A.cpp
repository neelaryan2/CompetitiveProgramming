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
    int n;
    cin >> n;
    vector<int> p(n), inv(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        inv[--p[i]] = i;
    }
    for (int i = n - 1; i >= 0; i--) {
        int m = inv[i], l = -1, r = -1;
        for (int k = m + 1; k < n; k++)
            if (p[k] < i) r = k;
        for (int k = m - 1; k >= 0; k--)
            if (p[k] < i) l = k;
        if (l != -1 && r != -1) {
            cout << "YES\n";
            l++, r++, m++;
            cout << l << ' ' << m << ' ' << r << '\n';
            return;
        }
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
