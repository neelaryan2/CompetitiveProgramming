#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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
    int n;
    cin >> n;
    vector<pii> arr(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr[i] = mp(a, i);
    }
    vector<int> left(n, -1), right(n, -1);
    sort(all(arr));
    multiset<int> intervals;
    size_t last = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int id = arr[i].se;
        int l = id, r = id;
        if (id > 0 && left[id - 1] != -1) {
            l = left[id - 1];
            left[id - 1] = -1;
            intervals.erase(id - l);
        }
        if (id < n - 1 && right[id + 1] != -1) {
            r = right[id + 1];
            right[id + 1] = -1;
            intervals.erase(r - id);
        }
        left[r] = l;
        right[l] = r;
        // cout << l << " " << r << endl;
        intervals.insert(r - l + 1);
        if (*intervals.begin() == *intervals.rbegin()) {
            if (intervals.size() > last) {
                last = intervals.size();
                ans = arr[i].fi + 1;
            }
        }
    }
    cout << ans << endl;
}