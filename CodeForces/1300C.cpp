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
    for (int b = 31; b >= 0; b--) {
        int cnt = 0, ind = -1;
        for (int i = 0; i < n; i++)
            if ((a[i] >> b) & 1) 
                ind = i, cnt++;
        if (cnt == 1) {
            swap(a[0], a[ind]);
            break;
        }
    }
    for (int& e : a) cout << e << ' ';
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
