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

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& e : arr) cin >> e;
    set<pii> s;
    for (int i = 0; i < n; i++) {
        s.insert({arr[i], i});
    }
    int ans = 1;
    auto it = s.begin();
    while (it != s.end()) {
        pii p = *it;
        auto it1 = s.lower_bound({p.fi + 1, -1});
        if (it1 == s.end()) break;
        auto it2 = s.lower_bound({it1->fi, p.se});
        if (it2 == s.end()) {
            ans++;
            break;
        }
        if (it2->fi != it1->fi) {
            ans++;
            it = it1;
        } else {
            it = it2;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}