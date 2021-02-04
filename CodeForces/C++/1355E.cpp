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
    ll N, A, R, M;
    cin >> N >> A >> R >> M;
    M = min(M, A + R);
    vector<ll> h(N);
    ll l = 1e9, r = 0;
    for (ll& e : h) {
        cin >> e;
        l = min(l, e);
        r = max(r, e);
    }
    auto cost = [&](int hei) {
        ll up = 0, down = 0;
        for (int e : h) {
            if (e < hei) down += hei - e;
            if (e > hei) up += e - hei;
        }
        ll ret;
        if (up > down)
            ret = (up - down) * R + down * M;
        else
            ret = (down - up) * A + up * M;
        return ret;
    };
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (cost(mid) < cost(mid + 1))
            r = mid;
        else
            l = mid + 1;
    }
    cout << cost(r) << '\n';
}
