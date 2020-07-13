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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    sort(all(a));
    int ans = 0;
    while (true) {
        ll cnt = 0, mn = -1;
        while (!a.empty() && cnt * mn < x) {
            cnt++, mn = a.back(), a.pop_back();
        }
        if (cnt * mn < x) break;
        ans++;
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
