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
#define rall(v) (v).rbegin(), (v).rend()

const int inf = 1e9 + 7;

void solve(int test) {
    int n;
    cin >> n;
    vector<int> w(n), l(n), pos(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        pos[--w[i]] = i;
    }
    for (int i = 0; i < n; i++)
        cin >> l[w[i]];
    int ans = 0;
    trace(pos, l);
    for (int i = 1; i < n; i++) {
        if (pos[i] > pos[i - 1]) continue;
        int need = pos[i - 1] - pos[i];
        need = 1 + (need / l[i]);
        ans += need;
        pos[i] += l[i] * need;
    }
    trace(pos);
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
