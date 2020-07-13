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
    int n, k;
    cin >> n >> k;
    k = (8 * k) / n;
    if (k >= 19) {
        cout << "0\n";
        return 0;
    }
    k = (1 << k);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        cnt[e]++;
    }
    vector<int> v(1, 0);
    for (pii p : cnt)
        v.eb(p.se);
    if (k + 1 >= v.size()) {
        cout << "0\n";
        return 0;
    }
    int ans = 0, m = v.size();
    for (int i = 1; i < m; i++)
        v[i] += v[i - 1];
    for (int i = 0; i + k < m; i++)
        ans = max(ans, v[i + k] - v[i]);
    cout << n - ans << '\n';
}
