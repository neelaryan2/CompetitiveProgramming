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

void solve(int test) {
    int n, k;
    cin >> n >> k;
    vector<pii> tb(n);
    for (int i = 0; i < n; i++)
        cin >> tb[i].se >> tb[i].fi;
    sort(rall(tb));
    trace(tb);
    ll tot = 0, ans = -1;
    multiset<int> t;
    for (int i = 0; i < n; i++) {
        ans = max(ans, tb[i].fi * (tot + tb[i].se));
        t.insert(tb[i].se);
        tot += tb[i].se;
        if (t.size() == k) {
            tot -= *t.begin();
            t.erase(t.begin());
        }
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
