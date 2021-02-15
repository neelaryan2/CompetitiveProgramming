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

void valid(string& s) {
    int n = s.size();
    int idx = 0;
    while (idx < n && s[idx] == '0')
        idx++;
    s = s.substr(idx, n - idx);
    if (idx == n && idx > 0)
        s = "0";
}
void solve(int test) {
    string s;
    cin >> s;
    valid(s);
    int n = s.size();
    vector<int> cnt(3, 0);
    vector<vi> vec(3);
    int tot = 0;
    for (int i = 0; i < n; i++) {
        int r = (s[i] - '0') % 3;
        cnt[r]++;
        vec[r].eb(i);
        tot = (tot + r) % 3;
    }
    if (tot == 0) {
        cout << s;
        return;
    }
    int fs = (s[0] - '0') % 3;
    if (cnt[tot] >= 2 || (cnt[tot] == 1 && fs != tot) || (fs == tot && n > 1 && s[1] != '0')) {
        s.erase(vec[tot].back(), 1);
    } else if (cnt[3 - tot] >= 2) {
        tot = 3 - tot;
        for (int t = 0; t < 2; t++) {
            s.erase(vec[tot].back(), 1);
            vec[tot].pop_back();
        }
    } else {
        assert(cnt[tot] == 1);
        s.erase(vec[tot].back(), 1);
    }
    valid(s);
    if (s == "") s = "-1";
    cout << s;
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
