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
    int n, x, cnt;
    cin >> n >> x;
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        s.insert(e);
    }
    int days = 0;
    while (true) {
        auto it = s.lb(1 + (x - 1) / 2);
        if (it == s.end()) break;
        int c = *it;
        if (c <= x) s.erase(it);
        x = 2 * min(x, c), days++;
    }
    days += s.size();
    cout << days << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
