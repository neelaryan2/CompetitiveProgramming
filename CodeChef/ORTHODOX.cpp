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
    vector<ll> a(n, 0);
    set<ll> s;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ord = 0;
    for (int i = 0; i < n; i++) {
        ord |= a[i];
        s.insert(ord);
    }
    ord = 0;
    for (int i = n - 1; i >= 0; i--) {
        ord |= a[i];
        s.insert(ord);
    }
    trace(s);
    puts(s.size() == (2 * n - 1) ? "YES" : "NO");
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
