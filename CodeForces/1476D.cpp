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
    vector<int> rightl(n), rightr(n);
    vector<int> leftl(n), leftr(n);
    rightl[n - 1] = (s[n - 1] == 'L');
    rightr[n - 1] = (s[n - 1] == 'R');
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == 'L') {
            rightl[i] = rightr[i + 1] + 1;
            rightr[i] = 0;
        } else {
            rightr[i] = rightl[i + 1] + 1;
            rightl[i] = 0;
        }
    }
    leftl[0] = (s[0] == 'L');
    leftr[0] = (s[0] == 'R');
    for (int i = 1; i < n; i++) {
        if (s[i] == 'L') {
            leftl[i] = leftr[i - 1] + 1;
            leftr[i] = 0;
        } else {
            leftr[i] = leftl[i - 1] + 1;
            leftl[i] = 0;
        }
    }
    trace(s);
    trace(leftl);
    trace(leftr);
    trace(rightl);
    trace(rightr);
    for (int i = 0; i <= n; i++) {
        int ans = 0;
        if (i == 0) {
            ans = rightr[i] + 1;
        } else if (i == n) {
            ans = leftl[i - 1] + 1;
        } else {
            ans = 1 + max(leftl[i - 1], rightr[i]);
            if (s[i - 1] == 'L' && s[i] == 'R')
                ans = 1 + leftl[i - 1] + rightr[i];
        }
        cout << ans << ' ';
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
