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
int kmp(string const& s) {
    int n = s.size();
    vector<int> lps(n, 0);
    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];
        while (j > 0 && s[i] != s[j])
            j = lps[j - 1];
        if (s[i] == s[j]) j++;
        lps[i] = j;
    }
    return lps.back();
}
void solve(int test) {
    string s, t;
    cin >> s >> t;
    int l = kmp(t);
    string t1 = t.substr(l, t.size() - l);
    string ans = t;
    while (ans.size() < s.size())
        ans += t1;
    while (ans.size() > s.size())
        ans.pop_back();
    int ca[] = {0, 0};
    for (char c : ans)
        ca[c - '0']++;
    for (char c : s)
        ca[c - '0']--;
    if (ca[0] > 0) {
        for (int i = s.size() - 1; i >= 0; i--)
            if (ans[i] == '0' && ca[0]) ans[i] = '1', ca[0]--;
    } else {
        for (int i = s.size() - 1; i >= 0; i--)
            if (ans[i] == '1' && ca[1]) ans[i] = '0', ca[1]--;
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
        cout << "\n";
    }
}
