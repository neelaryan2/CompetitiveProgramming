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

bool alpha(char c) {
    return 'a' <= c && c <= 'z';
}
bool num(char c) {
    return '0' <= c && c <= '9';
}
void solve(int test) {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dot, at;
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') dot.eb(i);
        if (s[i] == '@') at.eb(i);
    }
    ll ans = 0;
    for (int i = 0; i < at.size(); i++) {
        int j = lb(all(dot), at[i]) - dot.begin();
        if (j == dot.size()) break;
        int l = at[i], r = dot[j];
        bool bad = (r - l == 1);
        int nxt = i;
        for (int k = l + 1; k < r; k++)
            if (!alpha(s[k]) && !num(s[k])) {
                bad = true;
                if (s[k] == '@') nxt++;
            }
        if (bad) {
            if (nxt > i) i = nxt - 1;
            continue;
        }
        int lll = l - 1, rrr = r + 1;
        int lets = 0, org = 0;
        while (lll >= 0 && s[lll] != '.' && s[lll] != '@')
            lets += alpha(s[lll--]);
        while (rrr < n && alpha(s[rrr]))
            org++, rrr++;
        ans += 1LL * org * lets;
    }
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
