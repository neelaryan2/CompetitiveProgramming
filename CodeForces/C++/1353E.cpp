/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int cnt = 0, ans = n;
    for (char c : s)
        if (c == '1') cnt++;
    for (int i = 0; i < k; i++) {
        vector<int> vec;
        int cnt1 = 0;
        for (int j = i; j < n; j += k) {
            vec.pb(s[j] - '0');
            if (s[j] == '1') cnt1++;
        }
        int sz = vec.size();
        set<pii> st;
        int sum[2];
        sum[0] = 0, sum[1] = 0;
        st.insert(mp(0, -1));
        int cost = n;
        trace(vec);
        for (int j = 0; j < sz; j++) {
            trace(sum[0], sum[1], st);
            sum[vec[j]]++;
            st.insert(mp(sum[1] - sum[0], j));
            int cur = st.begin()->fi + sum[0] + cnt1 - sum[1];
            cost = min(cost, cur);
        }
        trace(cost);
        ans = min(ans, cnt - cnt1 + cost);
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
