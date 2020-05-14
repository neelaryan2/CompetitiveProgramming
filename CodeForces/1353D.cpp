/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using pii = pair<int, int>;
using ppi = pair<int, pii>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
void solve() {
    int n;
    cin >> n;
    vi a(n, 0);
    int T = 1;
    priority_queue<ppi> q;
    q.push({n, {0, n - 1}});
    while (!q.empty()) {
        int s = -q.top().se.fi;
        int e = q.top().se.se;
        int m = (s + e) / 2;
        a[m] = T++;
        q.pop();
        if (m - 1 >= s) q.push({m - s, {-s, m - 1}});
        if (e >= m + 1) q.push({e - m, {-m - 1, e}});
    }
    for (int& e : a) cout << e << " ";
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
