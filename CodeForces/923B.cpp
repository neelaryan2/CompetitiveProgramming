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
void solve(int test) {
    int n;
    cin >> n;
    vector<int> v(n), t(n);
    for (int& e : v) cin >> e;
    for (int& e : t) cin >> e;
    multiset<ll> s;
    ll off = 0;
    for (int i = 0; i < n; i++) {
        ll ans = 0;
        s.insert(v[i] + off);
        while (!s.empty() && *s.begin() <= t[i] + off) {
            auto it = s.begin();
            ans += *it - off;
            s.erase(it);
        }
        ans += 1LL * s.size() * t[i];
        off += t[i];
        cout << ans << ' ';
    }
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
        cout << "\n";
    }
}
