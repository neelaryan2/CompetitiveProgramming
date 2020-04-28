#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define pb push_back
#define eb emplace_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vi c(k), cnt(k, 0);
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        cnt[e - 1]++;
    }
    for (int& e : c) cin >> e;
    int sz = -1, sum = 0;
    for (int i = k - 1; i >= 0; i--) {
        sum += cnt[i];
        int cur = 1 + (sum - 1) / c[i];
        sz = max(sz, cur);
    }
    vector<vi> ans(sz);
    int cur = 0;
    for (int i = k - 1; i >= 0; i--) {
        while (cnt[i]--) {
            ans[cur].eb(i + 1);
            cur = (cur + 1) % sz;
        }
    }
    cout << sz << '\n';
    for (int i = 0; i < sz; i++) {
        cout << ans[i].size();
        for (int j : ans[i])
            cout << ' ' << j;
        cout << '\n';
    }
}