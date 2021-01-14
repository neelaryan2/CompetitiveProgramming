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
    k--;
    vector<int> a(n), b(n);
    for (int& e : a) cin >> e;
    for (int& e : b) cin >> e;
    sort(all(b));

    auto calc = [&](ll x) {
        // calc(x) <= k
        // calc(x+1) > k
        ll have = 0;
        for (int i = 0; i < n; i++)
            have += lb(all(b), x - a[i]) - b.begin();
        return have <= k;
    };

    ll lo = 1, hi = 2e9 + 1, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) / 2;
        if (calc(mid))
            lo = mid;
        else
            hi = mid;
    }
    cout << lo << '\n';
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
    }
}
