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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    if (k > 1e4) {
        cout << -1;
        return;
    }
    while (k) {
        int i = 0;
        for (; i + 1 < n; i++) {
            if (a[i] < a[i + 1]) {
                k--;
                a[i]++;
                if (k == 0) {
                    cout << (i + 1);
                    return;
                }
                break;
            }
        }
        if (i == n - 1) {
            cout << -1;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << '\n';
        trace("sda");
    }
}
