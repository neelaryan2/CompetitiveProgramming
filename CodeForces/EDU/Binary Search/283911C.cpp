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

int query(vector<int>& a, int q) {
    int n = a.size();
    int lo = -1, hi = n, mid;
    while (lo < hi - 1) {
        mid = lo + (hi - lo) / 2;
        if (a[mid] < q)
            lo = mid;
        else
            hi = mid;
    }
    return hi + 1;
}
void solve(int test) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    while (k--) {
        int q;
        cin >> q;
        int j = query(a, q);
        cout << j << '\n';
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
        cout << '\n';
    }
}
