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

int rec(vector<int>& a) {
    stack<int> st;
    int ans = 0;
    for (int e : a) {
        while (!st.empty() && st.top() < e) {
            ans = max(ans, st.top() ^ e);
            st.pop();
        }
        st.push(e);
    }
    while (st.size() > 1) {
        int e = st.top();
        st.pop();
        ans = max(ans, e ^ st.top());
    }
    return ans;
}
void solve(int test) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    int ans = rec(a);
    reverse(all(a));
    ans = max(ans, rec(a));

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
