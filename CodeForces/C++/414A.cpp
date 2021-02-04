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
    int t = n / 2;
    if (k < t || (n <= 1 && k != 0)) {
        cout << "-1\n";
        return 0;
    }
    if (n == 1) {
        cout << "1\n";
        return 0;
    }
    int q = k / t, r = k % t;
    vector<int> ans;
    for (int i = 0; i < 2 * r; i++)
        ans.eb((q + 1) * (2 * i + 1));
    for (int i = 0; i < n - 2 * r; i++)
        ans.eb(q * (2 * i + 1));

    int sc = 0;
    for (int i = 0; i + 1 < n; i += 2)
        sc += __gcd(ans[i], ans[i + 1]);
    assert(sc == k);

    for (int i : ans) cout << i << ' ';
    cout << '\n';
}
