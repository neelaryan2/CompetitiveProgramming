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
    string s;
    cin >> s;
    vector<int> ans(n);
    int cnt = 1;
    vector<int> v0, v1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (!v0.empty()) {
                int v = v0.back();
                v0.pop_back();
                v1.push_back(i);
                ans[i] = ans[v];
            } else {
                v1.push_back(i);
                ans[i] = cnt++;
            }
        } else {
            if (!v1.empty()) {
                int v = v1.back();
                v1.pop_back();
                v0.push_back(i);
                ans[i] = ans[v];
            } else {
                v0.push_back(i);
                ans[i] = cnt++;
            }
        }
    }
    cout << --cnt << '\n';
    for (int i : ans) cout << i << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
        cout << '\n';
    }
}
