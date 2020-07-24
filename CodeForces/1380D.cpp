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

void NO() {
    cout << "-1\n";
    exit(0);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    ll x, k, y;
    cin >> x >> k >> y;
    vector<int> a(n), b(m);
    for (int& e : a) cin >> e;
    for (int& e : b) cin >> e;
    a.eb(-1), b.eb(-1);
    if (m > n) NO();
    int l = 0;
    ll ans = 0;
    for (int i = 0; i <= m; i++) {
        int cnt = 0, mx = -1, bmax = b[i];
        ll cur = 0;
        if (i > 0) bmax = max(bmax, b[i - 1]);
        while (l <= n && a[l] != b[i])
            cnt++, mx = max(mx, a[l++]);
        if (l++ == n + 1) NO();
        if (cnt == 0) continue;
        if (cnt < k && mx > bmax) NO();
        int r = cnt % k, q = cnt / k;
        ans += r * y;
        if (q) {
            ans += (q - 1) * min(k * y, x);
            if (bmax > mx)
                ans += min(k * y, x);
            else
                ans += x;
        }
    }
    cout << ans << '\n';
}
