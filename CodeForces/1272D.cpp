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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    vector<int> dp1(n, 1);
    for (int i = 1; i < n; i++)
        if (a[i] > a[i - 1]) dp1[i] = dp1[i - 1] + 1;
    vector<int> dp2(n, 1);
    for (int i = n - 2; i >= 0; i--)
        if (a[i] < a[i + 1]) dp2[i] = dp2[i + 1] + 1;
    int ans = *max_element(all(dp1));
    for (int i = 1; i < n - 1; i++)
        if (a[i + 1] > a[i - 1])
            ans = max(ans, dp1[i - 1] + dp2[i + 1]);
    cout << ans << '\n';
}
