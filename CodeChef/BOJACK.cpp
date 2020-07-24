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
int ass(string s) {
    int n = s.size();
    map<string, int> cnt;
    int pal = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int l = j - i + 1;
            string t = s.substr(i, l);
            bool f = true;
            for (int k = 0; k < l; k++) {
                if (t[k] != t[l - k - 1]) f = false;
            }
            cnt[t]++;
            if (f) pal++;
        }
    }
    return cnt.size() - pal;
}
void solve(int test) {
    int D;
    cin >> D;
    cout << 2 * D + 1 << '\n';
    string a(D, 'a');
    string b(D + 1, 'b');
    string ans = a + b;
    cout << ans << '\n';
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
