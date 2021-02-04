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
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        p[e - 1] = i;
    }
    p.push_back(-1);
    int ans = (n == 1);
    for (int i = 1; i < n; i++) {
        int cnt = i;
        while (p[i] > p[i - 1]) i++;
        ans = max(ans, i - cnt + 1);
    }
    cout << n - ans << '\n';
}
