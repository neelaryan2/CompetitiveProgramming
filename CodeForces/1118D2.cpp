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
int n, m;
vector<int> arr;
bool check(int x) {
    ll res = 0;
    for (int i = 0; i < x; i++) {
        for (int j = i, t = 0; j < n; j += x, t++) {
            res += max(0, arr[j] - t);
        }
    }
    return (res >= m);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    arr.resize(n);
    for (int& e : arr) cin >> e;
    sort(all(arr));
    reverse(all(arr));
    int lo = 0, hi = n, mid;
    while (lo < hi - 1) {
        mid = lo + (hi - lo) / 2;
        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }
    if (!check(hi)) hi = -1;
    cout << hi << '\n';
}
