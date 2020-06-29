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
    int n, k;
    cin >> n >> k;
    set<int> s;
    int ans = n;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        s.insert(e);
    }
    while (!s.empty()) {
        int r = *s.begin(), cnt = 0;
        while (s.find(r) != s.end()) {
            s.erase(r);
            ll p = 1LL * r * k;
            cnt++;
            if (p > 1e9) break;
            r = p;
        }
        ans -= cnt / 2;
    }
    cout << ans << '\n';
}
