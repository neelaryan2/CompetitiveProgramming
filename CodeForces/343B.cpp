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
    stack<char> st;
    for (char c : s) {
        if (st.empty()) {
            st.push(c);
            continue;
        }
        char a = st.top();
        if (a != c)
            st.push(c);
        else
            st.pop();
    }
    puts(st.empty() ? "Yes" : "No");
}
