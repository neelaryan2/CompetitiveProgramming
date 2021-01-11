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
    string s;
    cin >> n >> s;
    int lcnt = 0, rcnt = 0;
    int lsum = 0, rsum = 0;
    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            if (s[i] == '?')
                lcnt++;
            else
                lsum += (s[i] - '0');
        } else {
            if (s[i] == '?')
                rcnt++;
            else
                rsum += (s[i] - '0');
        }
    }
    if (lsum == rsum) {
        cout << ((lcnt == rcnt) ? "Bicarp" : "Monocarp");
        return;
    }
    if (lsum > rsum) {
        swap(lsum, rsum);
        swap(lcnt, rcnt);
    }
    if (lcnt <= rcnt) {
        cout << "Monocarp";
        return;
    }
    int tmp = 9 * ((lcnt - rcnt) / 2);
    cout << ((tmp == rsum - lsum) ? "Bicarp" : "Monocarp");
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
