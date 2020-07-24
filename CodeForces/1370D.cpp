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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    auto check = [&](int x, int p) {
        int cnt = 0;
        for (int& e : a) {
            if (cnt % 2 == p && e > x) continue;
            if (++cnt >= k) return true;
        }
        return false;
    };
    int lo = 0, hi = 1e9, mid;
    while (lo < hi - 1) {
        mid = lo + (hi - lo) / 2;
        if (check(mid, 0) || check(mid, 1))
            hi = mid;
        else
            lo = mid;
    }
    cout << hi << '\n';
}
