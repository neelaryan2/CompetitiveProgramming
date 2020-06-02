/* Author - Neel Aryan (@neelaryan2) */
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

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    int cnt0 = 0, cnt1 = 0;
    for (int& e : a) {
        cin >> e;
        if (e % 2 == 0) cnt0++;
        if (e % 2) cnt1++;
    }
    for (int i = 1; i <= min(x, cnt1); i += 2) {
        int e = x - i;
        if (e <= cnt0) {
            puts("Yes");
            return;
        }
    }
    puts("No");
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
