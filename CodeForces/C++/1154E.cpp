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
using lt = list<int>::iterator;

void solve(int test) {
    int n, k;
    cin >> n >> k;
    vector<int> inv(n);
    list<int> a;
    vector<bool> done(n, false);
    vector<lt> its(n);
    for (int i = 0, e; i < n; i++) {
        cin >> e, e--;
        inv[e] = i;
        a.push_back(e);
        its[e] = prev(a.end());
    }
    string ans(n, '0');
    int t = 1;
    for (int j = n - 1; j >= 0; j--) {
        if (done[j]) continue;
        lt l = its[j], r = its[j];
        r++;
        for (int i = 0; i < k; i++) {
            if (l != a.begin()) l--;
            if (r != a.end()) r++;
        }
        for (lt it = l; it != r; it++) {
            ans[inv[*it]] = (t ? '1' : '2');
            done[*it] = true;
        }
        a.erase(l, r);
        t ^= 1;
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
