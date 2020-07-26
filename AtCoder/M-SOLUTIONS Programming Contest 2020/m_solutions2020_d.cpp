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
    vector<int> a(n);
    for (int& e : a) cin >> e;
    ll funds = 1000, stocks = 0;
    bool buy = true;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            if (!buy) {
                funds += stocks * a[i];
                stocks = 0;
                buy = true;
            }
        }
        if (a[i] < a[i + 1]) {
            if (buy) {
                stocks += funds / a[i];
                funds %= a[i];
                buy = false;
            }
        }
    }
    if (!buy) funds += stocks * a[n - 1];
    cout << funds;
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
