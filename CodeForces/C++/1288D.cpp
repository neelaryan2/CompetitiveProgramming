#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
int n, m, l, r;
vector<vi> arr;
bool check(int x) {
    int k = (1 << m);
    vector<int> msks(k, 0);
    for (int i = 0; i < n; i++) {
        int msk = 0;
        for (int j = 0; j < m; j++) {
            if (arr[i][j] >= x) {
                msk += (1 << j);
            }
        }
        msks[msk] = i + 1;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (msks[i] && msks[j] && (i | j) == k - 1) {
                l = msks[i], r = msks[j];
                if (l > r) swap(l, r);
                return true;
            }
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    arr.assign(n, vi(m));
    int mn = INT_MAX, mx = -1;
    for (vi& v : arr) {
        for (int& e : v) {
            cin >> e;
            mx = max(mx, e);
            mn = min(mn, e);
        }
    }
    int lo = mn, hi = mx + 1, mid;
    while (lo < hi - 1) {
        mid = lo + (hi - lo) / 2;
        if (check(mid))
            lo = mid;
        else
            hi = mid;
    }
    bool b = check(lo);
    cout << l << ' ' << r << '\n';
}