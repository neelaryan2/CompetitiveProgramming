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
    int px, py;
    cin >> px >> py;
    string s;
    cin >> s;
    int n = s.size();
    int u, d, r, l;
    u = d = r = l = 0;
    for (char ch : s) {
        if (ch == 'U') u++;
        if (ch == 'D') d++;
        if (ch == 'R') r++;
        if (ch == 'L') l++;
    }
    if ((-l <= px && px <= r) && (-d <= py && py <= u)) {
        cout << "YES";
    } else
        cout << "NO";
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
