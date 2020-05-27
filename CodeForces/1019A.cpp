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
#define rall(v) (v).rbegin(), (v).rend()
const ll inf = 1e18;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vi> v(m);
    for (int i = 0; i < n; i++) {
        int p, c;
        cin >> p >> c;
        v[p - 1].pb(c);
    }
    for (int i = 0; i < m; i++)
        sort(rall(v[i]));
    auto cost = [&](int x) {
        ll ret = 0, cnt = 0;
        vector<int> vec;
        for (int i = 1; i < m; i++) {
            int sz = v[i].size();
            for (int j = x - 1; j < sz; j++)
                ret += v[i][j], cnt++;
            for (int j = 0; j < min(x - 1, sz); j++)
                vec.pb(v[i][j]);
        }
        x -= cnt + v[0].size();
        if (x < 0) return ret;
        sort(rall(vec));
        trace(vec);
        while (x) {
            ret += vec.back();
            vec.pop_back();
            x--;
        }
        return ret;
    };
    int l = 1, r = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (cost(mid) < cost(mid + 1))
            r = mid;
        else
            l = mid + 1;
    }
    cout << cost(r) << '\n';
}
