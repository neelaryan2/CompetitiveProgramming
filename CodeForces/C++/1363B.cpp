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

void solve() {
    string a;
    cin >> a;
    int n = a.size();
    multiset<char> s;
    for (char c : a) {
        s.insert(c);
        auto it = s.ub(c);
        if (it != s.end()) s.erase(it);
    }
    int ans = s.size();
    s.clear();
    reverse(all(a));
    for (char c : a) {
        s.insert(c);
        auto it = s.ub(c);
        if (it != s.end()) s.erase(it);
    }
    ans = max(ans, (int)s.size());
    cout << n - ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
