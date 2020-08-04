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

void solve(int test) {
    int k;
    cin >> k;
    int num = 7 % k, cnt = 1;
    map<int, int> seen;
    while (seen.find(num) == seen.end()) {
        seen[num] = 1;
        if(!num) break;
        num = (10 * num + 7) % k;
        cnt++;
    }
    if (seen.find(0) == seen.end()) cnt = -1;
    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
