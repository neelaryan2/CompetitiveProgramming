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
    int n = 6;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    int ans = (a[0] + a[1] + a[2]);
    ans = ans * ans;
    ans -= a[0] * a[0];
    ans -= a[2] * a[2];
    ans -= a[4] * a[4];
    cout << ans << '\n';
}
