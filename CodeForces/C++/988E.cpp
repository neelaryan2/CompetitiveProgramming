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

int transform(string& s, char ch) {
    int n = s.size(), idx = -1;
    for (int i = n - 1; i >= 0; i--)
        if (s[i] == ch) {
            idx = i;
            break;
        }
    if (idx == -1) return inf;
    int cnt = 0;
    for (int i = idx + 1; i < n; i++) {
        swap(s[i], s[i - 1]);
        cnt++;
    }
    s.pop_back();
    return cnt;
}

int count(string s, string t) {
    int m = t.size(), n = s.size();
    if (n < m) return inf;
    int cnt = 0, cur;
    for (int i = m - 1; i >= 0; i--) {
        cur = transform(s, t[i]);
        if (cur == inf) return inf;
        cnt += cur;
    }
    cur = 0;
    while (cur < n - m && s[cur] == '0')
        cur++;
    if (cur == n - m && cur) return inf;
    return cnt + cur;
}

void solve(int test) {
    string s;
    cin >> s;
    int ans = inf;
    ans = min(ans, count(s, "00"));
    ans = min(ans, count(s, "25"));
    ans = min(ans, count(s, "50"));
    ans = min(ans, count(s, "75"));
    if (ans == inf) ans = -1;
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
