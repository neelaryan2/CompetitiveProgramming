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
    string s, t;
    cin >> n >> s >> t;
    while (!s.empty() && s.back() == t.back()) {
        s.pop_back();
        t.pop_back();
        n--;
    }
    reverse(all(s));
    reverse(all(t));
    while (!s.empty() && s.back() == t.back()) {
        s.pop_back();
        t.pop_back();
        n--;
    }
    int ans = 0;
    ans += (s.substr(1, n - 1) == t.substr(0, n - 1));
    ans += (s.substr(0, n - 1) == t.substr(1, n - 1));
    cout << ans;
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
