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
    int n;
    cin >> n;
    map<string, int> sc;
    vector<int> scores(n);
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> scores[i];
        sc[s[i]] += scores[i];
    }
    int mx = -1e9;
    for (auto p : sc)
        mx = max(mx, p.se);
    set<string> st;
    for (auto p : sc)
        if (p.se == mx) 
            st.insert(p.fi);
    sc.clear();
    for (int i = 0; i < n; i++) {
        auto it = st.find(s[i]);
        if (it == st.end()) continue;
        sc[s[i]] += scores[i];
        if (sc[s[i]] >= mx) {
            cout << s[i] << '\n';
            return 0;
        }
    }
}
