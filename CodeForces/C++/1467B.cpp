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
const int N = 31;
const ll inf = 1e18;
void solve(int test) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& e : a) 
        cin >> e;

    auto func = [&](int i) {
        if (i <= 0 || i >= n - 1)
            return 0;
        if (a[i - 1] > a[i] && a[i + 1] > a[i])
            return 1;
        if (a[i - 1] < a[i] && a[i + 1] < a[i])
            return 1;
        return 0;
    };
    auto get = [&](int i) {
        return func(i - 1) + func(i) + func(i + 1);
    };

    int cnt = 0;
    for (int i = 1; i < n - 1; i++)
        cnt += func(i);

    int ans = cnt;
    for (int i = 1; i < n - 1; i++) {
        if (!func(i)) continue;
        int old = a[i], cur = cnt;
        cur -= get(i);
        a[i] = a[i + 1];
        ans = min(ans, cur + get(i));
        a[i] = a[i - 1];
        ans = min(ans, cur + get(i));
        a[i] = old;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << '\n';
    }
}
