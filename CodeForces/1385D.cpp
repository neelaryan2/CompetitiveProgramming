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
string s;
int n;
int sex(int l, int r, char c) {
    if (l == r) return s[l] != c;
    int m = (l + r) / 2, k = (r - l + 1) / 2;
    int cntl = 0, cntr = 0;
    for (int i = l; i <= m; i++)
        cntl += s[i] == c;
    for (int i = m + 1; i <= r; i++)
        cntr += s[i] == c;
    int lef = sex(l, m, c + 1) + k - cntr;
    int righ = sex(m + 1, r, c + 1) + k - cntl;
    trace(l, r, c, lef, righ);
    return min(lef, righ);
}
void solve(int test) {
    cin >> n >> s;
    trace(s, n);
    cout << sex(0, n - 1, 'a') << '\n';
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
