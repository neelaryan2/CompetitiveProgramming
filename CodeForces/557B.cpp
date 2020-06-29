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
    int n, w;
    cin >> n >> w;
    vector<int> a(2 * n);
    for (int& e : a) cin >> e;
    sort(all(a));
    ld x = min((ld)a[0], (ld)a[n] / 2);
    x = min(x * 3 * n, (ld)w);
    cout << fixed << setprecision(10) << x << '\n';
}
