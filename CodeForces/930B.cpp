/* Author - Neel Aryan (@neelaryan2) */
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
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    vector<string> ch[26];
    for (int i = 0; i < n; i++) {
        string t = s.substr(n - i, i) + s.substr(0, n - i);
        ch[t[0] - 'a'].pb(t);
    }
    int num = 0;
    ld ans = 0;
    for (int i = 0; i < 26; i++) {
        int k = ch[i].size();
        if (k == 0) continue;
        vector<int> has(n, 0);
        for (int j = 0; j < n; j++) {
            vector<int> cnt(26, 0);
            for (string& t : ch[i])
                cnt[t[j] - 'a']++;
            for (string& t : ch[i])
                if (cnt[t[j] - 'a'] == 1)
                    has[j]++;
        }
        ld h = *max_element(all(has));
        ans += h / n;
    }
    cout << fixed << setprecision(15) << ans << '\n';
}
