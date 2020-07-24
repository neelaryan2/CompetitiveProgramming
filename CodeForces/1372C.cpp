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
    vector<int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        if (a[i] != i) cnt++;
    }
    if (cnt == 0) {
        cout << "0\n";
        return;
    }
    int l = 0, r = n - 1;
    while (l < n && a[l] == l) l++;
    while (r < n && a[r] == r) r--;
    bool flag = true;
    for (int i = l; i <= r; i++)
        if (a[i] == i) flag = false;
    int ans = 2;
    if (flag) ans = 1;
    cout << ans << '\n';
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
