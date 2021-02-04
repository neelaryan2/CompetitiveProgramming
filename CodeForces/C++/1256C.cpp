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
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> c(m);
    int ex = n;
    for (int& e : c) {
        cin >> e;
        ex -= e;
    }
    int blanks = (d - 1) * (m + 1);
    if (ex > blanks) {
        cout << "NO";
        return;
    }
    vector<int> ans(n, 0);
    int ptr = min(ex, d - 1);
    ex -= ptr;
    for (int i = 0; i < m; i++) {
        while (c[i]--)
            ans[ptr++] = i + 1;
        int t = min(ex, d - 1);
        ptr += t;
        ex -= t;
    }
    cout << "YES\n";
    for (int i : ans)
        cout << i << ' ';
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
