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
    int n;
    cin >> n;
    vector<int> cnt(n, 0);
    if (n % 2 == 0) {
        int t = 1;
        for (int i = n - 1; i >= 0; i--) {
            int s = t ? 1 : -1;
            int ss = i;
            if (t) {
                cout << "0 ";
                ss--;
            }
            while (ss--) {
                cout << s << ' ';
                s = -s;
            }
            t ^= 1;
        }
    } else {
        int t = 1;
        for (int i = n - 1; i >= 0; i--) {
            int s = 1;
            int ss = i;
            while (ss--) {
                cout << s << ' ';
                s = -s;
            }
            t ^= 1;
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
    }
}
