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
int B = 200;

void solve(int test) {
    int n, q, m;
    cin >> n >> q >> m;
    B = ceil(sqrtl(q));

    vector<int> arr(n), cnt(m + 1, 0);
    vector<vi> vec(B);

    for (int& e : arr)
        cin >> e;

    cnt[0] = q;
    while (q--) {
        int l, r, a, d;
        cin >> l >> r;
        l--, r--;
        a = arr[l];
        d = arr[l] + arr[r];
        if (d >= B) {
            for (int k = 0; k <= m; k += d) {
                // [k,k+a[l]) is losing
                cnt[k]--;
                if (k + a <= m)
                    cnt[k + a]++;
            }
        } else {
            vec[d].eb(a);
        }
    }
    for (int i = 0; i < B; i++) {
        vi& v = vec[i];
        if (v.empty())
            continue;
        int k = *max_element(all(v)) + 1;
        assert(k <= i);
        vi block(k, 0);
        block[0] -= (int)v.size();
        for (int t : v)
            block[t]++;
        for (int j = 0; j <= m; j += i)
            for (int t = 0; t < min(k, m - j + 1); t++)
                cnt[j + t] += block[t];
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        cnt[i] += cnt[i - 1];
        ans = max(ans, cnt[i]);
    }
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
