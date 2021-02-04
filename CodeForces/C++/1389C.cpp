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
    string s;
    cin >> s;
    int n = s.size(), ans = n;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int t = 0, cnt = 0;
            for (char ch : s) {
                int c = ch - '0';
                int k = t ? i : j;
                if (c != k) continue;
                cnt++, t ^= 1;
            }
            if (i != j && (cnt & 1)) cnt--;
            ans = min(ans, n - cnt);
        }
    }
    cout << ans;
    return;
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
        cout << "\n";
    }
}
