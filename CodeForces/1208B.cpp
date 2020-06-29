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
    vector<int> a(n);
    for (int& e : a) cin >> e;
    int ans = n + 10;
    for (int i = 0; i <= n; i++) {
        set<int> s;
        for (int j = 0; j < i; j++)
            s.insert(a[j]);
        for (int j = n - 1; j >= i; j--) {
            if (s.size() == n - j + i - 1)
                ans = min(ans, j - i + 1);
            s.insert(a[j]);
        }
        if (s.size() == n) ans = 0;
    }
    cout << ans << '\n';
}
