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
const int N = 4e5;
vi cnt(N, 0);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a;
    cin >> a;
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += int(s[j] - '0');
            cnt[sum]++;
        }
    }
    ll ans = 0;
    if (a == 0) {
        for (int i = 0; i < N; i++)
            ans += 2 * cnt[i];
        ans = cnt[0] * (ans - cnt[0]);
    } else {
        for (int i = 1; i < N; i++) {
            int j = a / i;
            if (a % i || j >= N) continue;
            ans += 1LL * cnt[i] * cnt[j];
        }
    }
    cout << ans << '\n';
}
