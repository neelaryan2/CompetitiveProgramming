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
    int n, m;
    cin >> n >> m;
    vector<int> p(n + 1), cnt(n + 1), nxt(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    int rt = sqrtl(n) + 1;
    auto update = [&](int i) {
        int j = i + p[i];
        if (j > n) {
            nxt[i] = -1;
            cnt[i] = 1;
        } else if (j / rt != i / rt) {
            nxt[i] = j;
            cnt[i] = 1;
        } else {
            nxt[i] = nxt[j];
            cnt[i] = cnt[j] + 1;
        }
    };
    for (int i = n; i >= 1; i--)
        update(i);
    while (m--) {
        int t, a, b;
        cin >> t >> a;
        if (t == 0) {
            cin >> b;
            p[a] = b;
            int l = (a / rt) * rt;
            for (int i = a; i >= l; i--)
                update(i);
        }
        if (t == 1) {
            int ans = 0;
            while (nxt[a] != -1)
                ans += cnt[a], a = nxt[a];
            ans += cnt[a];
            while (a + p[a] <= n) 
                a += p[a];
            cout << a << ' ' << ans << '\n';
        }
    }
}
