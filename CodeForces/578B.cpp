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
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, x;
    cin >> n >> k >> x;
    int p = 1;
    while (k--) p *= x;
    vector<int> pref(n, 0), a(n), suf(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] | a[i - 1];
        suf[n - i - 1] = suf[n - i] | a[n - i];
    }
    ll ans = 0, cur;
    for (int i = 0; i < n; i++) {
        cur = 1LL * a[i] * p;
        cur |= 1LL * pref[i];
        cur |= 1LL * suf[i];
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}
