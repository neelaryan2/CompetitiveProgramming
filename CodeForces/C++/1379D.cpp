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
    int n, h, m, k;
    cin >> n >> h >> m >> k;
    int mod = m / 2;
    vector<int> mm(n), t;
    for (int i = 0, _; i < n; i++) {
        cin >> _ >> mm[i];
        mm[i] %= mod;
        t.eb(mm[i]), t.eb(mm[i] - mod);
    }
    sort(all(t));
    int ans = n, T = -1;
    trace(t);
    for (int i = n; i < 2 * n; i++) {
        int j = ub(all(t), t[i] - k) - t.begin();
        if (i - j < ans)
            ans = i - j, T = t[i];
    }
    cout << ans << ' ' << T << '\n';
    if (T - k < 0) {
        for (int i = 0; i < n; i++)
            if (T > mm[i] || mm[i] > T - k + mod)
                cout << i + 1 << ' ';
    } else {
        for (int i = 0; i < n; i++)
            if (T - k < mm[i] && mm[i] < T)
                cout << i + 1 << ' ';
    }
    cout << '\n';
}
