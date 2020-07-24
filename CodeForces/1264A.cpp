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

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int& e : p) cin >> e;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int count = 1;
        while (i < n - 1 && p[i] == p[i + 1])
            count++, i++;
        v.eb(count);
    }
    int k = v.size();
    int g = v[0], s = 0, b = 0, i = 1;
    while (i < k && s <= g) s += v[i++];
    while (i < k && b <= g) b += v[i++];
    while (i < k && g + s + b + v[i] <= n / 2) b += v[i++];
    if (g + s + b > n / 2) g = s = b = 0;
    cout << g << ' ' << s << ' ' << b << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
