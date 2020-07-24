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
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    auto cost = [&](int k) {
        vector<ll> b(n);
        for (int i = 0; i < n; i++)
            b[i] = a[i] + 1LL * (i + 1) * k;
        sort(all(b));
        ll sm = 0;
        for (int i = 0; i < k; i++)
            sm += b[i];
        return sm;
    };
    int lo = 0, hi = n + 1, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) / 2;
        if (cost(mid) <= s)
            lo = mid;
        else
            hi = mid;
    }
    cout << lo << ' ' << cost(lo) << '\n';
}
