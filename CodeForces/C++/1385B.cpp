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
    int n;
    cin >> n;
    vector<int> a(2 * n);
    vector<int> id(n, -1), done(n, 0);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i], a[i]--;
        id[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        if (done[a[i]]) continue;
        int j = id[a[i]];
    }
    sort(all(id));
    for (int i : id) cout << a[i] + 1 << ' ';
    cout << '\n';
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
