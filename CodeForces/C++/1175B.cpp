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

void solve(int test) {
    int nl;
    cin >> nl;
    ll x = 0;
    ll up = 1LL << 32;
    stack<ll> st;
    st.push(1);
    while (nl--) {
        string s;
        cin >> s;
        if (s == "add") {
            x += st.top();
            if (x >= up) {
                cout << "OVERFLOW!!!";
                return;
            }
        } else if (s == "for") {
            int n;
            cin >> n;
            st.push(min(up, n * st.top()));
        } else if (s == "end") {
            st.pop();
        }
    }
    cout << x;
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
