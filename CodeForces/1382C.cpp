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
    string a, b;
    cin >> n >> a >> b;
    vector<int> ans;
    int ref = a[0];
    for (int i = n - 1, cnt = 1; i >= 0; i--, cnt++) {
        if (b[i] == ref) ans.eb(1);
        ans.eb(i + 1), ref = a[cnt / 2];
        if (cnt & 1) ref = a[n - (1 + cnt) / 2] ^ 1;
    }
    cout << ans.size() << ' ';
    for (int i : ans) cout << i << ' ';
    cout << '\n';
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
