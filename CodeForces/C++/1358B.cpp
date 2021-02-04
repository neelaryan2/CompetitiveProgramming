/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    sort(all(a));
    ll sum = 0, cnt = 1;
    for (int i = 0; i < n; i++) {
        if (sum + cnt >= a[i]) {
            cnt += sum + 1;
            sum = 0;
        } else {
            sum++;
        }
    }
    cout << cnt << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
