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
    vector<int> a;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        cnt[e]++;
        a.eb(e);
    }
    string ans = "cslnb";
    int cnt2 = 0, f = 0;
    for (pii p : cnt) {
        if (p.se > 2) {
            cout << ans << '\n';
            return 0;
        }
        if (p.se == 2) {
            f = p.fi;
            cnt2++;
        }
    }
    if (cnt2 > 1 || (cnt2 == 1 && f == 0)) {
        cout << ans << '\n';
        return 0;
    }
    if (cnt2 == 1) {
        if (cnt[f - 1]) {
            cout << ans << '\n';
            return 0;
        }
        for (int i = 0; i < n; i++)
            if (a[i] == f) {
                a[i]--;
                break;
            }
    }
    sort(all(a));
    ll tot = 0;
    for (int i = 0; i < n; i++)
        tot += a[i] - i;
    trace(tot);
    if (tot % 2 != cnt2) ans = "sjfnb";
    cout << ans << '\n';
}
