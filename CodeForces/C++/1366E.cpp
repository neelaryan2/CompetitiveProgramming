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
const int mod = 998244353;
const int inf = 1e9 + 10;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int& e : a) cin >> e;
    for (int& e : b) cin >> e;
    int j = n - 1, ans = 1;
    for (int i = m - 1; i >= 0; i--) {
        while (j >= 0 && a[j] != b[i]) {
            if (a[j] < b[i]) {
                ans = 0;
                break;
            }
            j--;
        }
        if (j < 0) {
            ans = 0;
            break;
        }
        int cur = j;
        while (j >= 0 && a[j] >= b[i]) j--;
        if (i == 0) break;
        if (j < 0) {
            ans = 0;
            break;
        }
        cur -= j;
        trace(i, cur);
        ans = (1LL * ans * cur) % mod;
    }
    if (j != -1) ans = 0;
    cout << ans << '\n';
}
