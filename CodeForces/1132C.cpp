/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<vi> vec(n);
    vector<vi> cnt(q, vi(q, 0));
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        for (int j = l; j <= r; j++) {
            if (vec[j].size() >= 3) continue;
            vec[j].pb(i);
        }
    }
    int ans = n;
    for (int i = 0; i < n; i++) {
        if (vec[i].size() >= 3) continue;
        if (vec[i].size() == 2) {
            cnt[vec[i][0]][vec[i][1]]++;
            cnt[vec[i][1]][vec[i][0]]++;
        } else if (vec[i].size() == 1) {
            for (int j = 0; j < q; j++) {
                if (j == vec[i][0]) continue;
                cnt[vec[i][0]][j]++;
                cnt[j][vec[i][0]]++;
            }
        } else
            ans--;
    }
    int mn = n + 5;
    for (int i = 0; i < q; i++)
        for (int j = i + 1; j < q; j++)
            mn = min(mn, cnt[i][j]);
    cout << ans - mn << '\n';
}
