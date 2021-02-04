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
int query(vector<int>& q) {
    cout << "? " << q.size();
    for (int i : q)
        cout << " " << i + 1;
    cout << endl;
    int mx = -1;
    cin >> mx;
    // vector<int> arr = {1, 2, 3, 4};
    // for (int i : q)
    //     mx = max(arr[i], mx);
    q.clear();
    return mx;
}
int query(int l, int r) {
    cout << "? " << r - l + 1;
    for (int i = l; i <= r; i++)
        cout << " " << i + 1;
    cout << endl;
    int mx = -1;
    cin >> mx;
    // vector<int> arr = {1, 2, 3, 4};
    // for (int i = l; i <= r; i++)
    //     mx = max(arr[i], mx);
    return mx;
}
void write_ans(vector<int>& arr) {
    cout << "!";
    for (int i : arr)
        cout << " " << i;
    cout << endl;
    string s;
    cin >> s;
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<vi> ind(k);
    for (int i = 0; i < k; i++) {
        int sz;
        cin >> sz;
        ind[i].resize(sz);
        for (int j = 0; j < sz; j++) {
            cin >> ind[i][j];
            ind[i][j]--;
        }
    }
    vector<int> q(n);
    iota(all(q), 0);
    int mx = query(q);
    int lo = 0, hi = n, mid;
    while (lo < hi - 1) {
        mid = lo + (hi - lo) / 2;
        int cur = query(lo, mid - 1);
        if (cur == mx)
            hi = mid;
        else
            lo = mid;
    }
    vector<int> ans(k, mx);
    int id = -1;
    for (int i = 0; i < k; i++) {
        for (int j : ind[i]) {
            if (lo == j) {
                id = i;
                break;
            }
        }
        if (id != -1) break;
    }
    if (id == -1) return write_ans(ans);
    vector<bool> done(n, false);
    for (int i : ind[id])
        done[i] = true;
    for (int i = 0; i < n; i++)
        if (!done[i]) q.pb(i);
    mx = query(q);
    ans[id] = mx;
    write_ans(ans);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
