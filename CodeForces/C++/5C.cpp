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
#define ub upper_bound
#define lb lower_bound
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
    stack<int> st;
    vector<int> c(n, -1);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
            continue;
        }
        if (st.empty()) continue;
        int j = st.top();
        st.pop();
        if (s[j] == ')') continue;
        c[i] = j;
        trace(i, j);
        while (j > 0 && c[j - 1] >= 0)
            c[i] = c[j - 1], j = c[j - 1];
    }
    trace(c);
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || c[i] == -1) continue;
        ans1 = max(ans1, i - c[i] + 1);
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || c[i] == -1) continue;
        if (ans1 == i - c[i] + 1) ans2++;
    }
    if (ans1 == 0) ans2 = 1;
    cout << ans1 << ' ' << ans2 << '\n';
}
