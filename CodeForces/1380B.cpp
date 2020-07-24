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
    string s;
    cin >> s;
    int cntr = 0, cnts = 0, cntp = 0;
    for (char c : s) {
        if (c == 'R') cntr++;
        if (c == 'S') cnts++;
        if (c == 'P') cntp++;
    }
    char ans;
    int mx = max({cntr, cnts, cntp});
    if (mx == cntr) ans = 'P';
    if (mx == cntp) ans = 'S';
    if (mx == cnts) ans = 'R';
    for (int i = 0; i < s.size(); i++)
        cout << ans;
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
