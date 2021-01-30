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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int& e : a) cin >> e;
    for (int& e : b) cin >> e;
    int ptr1 = 0, ptr2 = 0;
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        while (ptr1 < n && a[ptr1] < b[i])
            ptr1++;
        while (ptr2 < n && a[ptr2] <= b[i])
            ptr2++;
        ans += ptr2 - ptr1;
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
