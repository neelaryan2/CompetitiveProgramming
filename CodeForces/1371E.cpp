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
    int n, p;
    cin >> n >> p;
    vector<int> a(n), b(2 * n), ans;
    multiset<int> s;
    for (int& e : a) cin >> e;
    sort(all(a));
    int m = a.back(), off = m - n + 1;
    for (int i = 0; i < 2 * n; i++) {
        int& cur = b[i];
        cur = ub(all(a), off + i) - a.begin();
        cur = (off + i - cur) % p;
        if (cur < 0) cur += p;
        if (i < n) s.insert(cur);
    }
    for (int x = m - n + 1; x < m; x++) {
        int cur = x % p;
        if (cur < 0) cur += p;
        if (s.find(cur) == s.end()) ans.eb(x);
        s.erase(s.find(b[x - off]));
        s.insert(b[x - off + n]);
    }
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
    cout << '\n';
}
