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
    string a, b;
    cin >> a >> b;
    vector<int> v, cnt(2, 0);
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            cnt[a[i] - '0']++;
            v.eb(a[i] - '0');
        }
    }
    if (cnt[1] != cnt[0]) {
        cout << "-1\n";
        return 0;
    }
    cnt = {0, 0};
    for (int e : v) {
        if (cnt[e ^ 1]) 
            cnt[e ^ 1]--;
        cnt[e]++;
    }
    int ans = cnt[0] + cnt[1];
    cout << ans << '\n';
}
