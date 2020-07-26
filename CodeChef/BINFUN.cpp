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
int msb(int x) {
    return 31 - __builtin_clz(x);
}
void solve(int test) {
    trace(test);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vi> num(30);
    for (int& e : a) {
        cin >> e;
        int b = msb(e);
        num[b].eb(e);
    }
    ll ans = 0;
    for (int i = 0; i < 30; i++) {
        if (num[i].size() <= 1) continue;
        sort(all(num[i]));
        ll diff = num[i].back() - num[i][0];
        ll coef = (1LL << (i + 1) - 1);
        coef *= diff;
        trace(num[i], coef);
        ans = max(ans, coef);
    }
    for (int i = 0; i < n; i++) {
        ll x = a[i];
        int bb = msb(x);
        ll coef = (1LL << (bb + 1)) - 1;
        for (int b = 0; b < 30; b++) {
            if (num[b].empty()) continue;
            ll cur = (1LL << (b + 1)) - 1;
            cur = cur * x - coef * num[b][0];
            trace(num[b], cur);
            ans = max(ans, cur);
        }
    }
    cout << ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << "\n";
    }
}
