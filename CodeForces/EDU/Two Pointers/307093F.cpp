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
#define rall(v) (v).rbegin(), (v).rend()

const int inf = 1e9 + 7;

void solve(int test) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll& e : a)
        cin >> e;
    multiset<ll> s;
    int ptr = 0;
    ll ans = 0;

    // vector<pii> tmp;
    // for (int i = 0; i < n; i++) {
    //     ll mn = inf, mx = -1;
    //     for (int j = i; j >= 0; j--) {
    //         mn = min(mn, a[j]);
    //         mx = max(mx, a[j]);
    //         if (mx - mn <= k)
    //             tmp.eb(j, i);
    //     }
    // }
    // trace(tmp.size());
    // trace(tmp);

    for (int i = 0; i < n; i++) {
        s.insert(a[i]);
        while (ptr <= i && (*s.rbegin() - *s.begin()) > k)
            s.erase(s.find(a[ptr++]));
        ans += i - ptr + 1;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << '\n';
    }
}
