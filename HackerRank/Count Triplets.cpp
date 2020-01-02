#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<int, ll> pairs;
map<int, int> cnt;
int main() {
    int n; ll r, curr, c, k, ans = 0;
    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        cin >> curr;
        if (cnt.find(curr) == cnt.end())
            cnt[curr] = 0;
        cnt[curr]++;
        if (r == 1 || curr % r) continue;
        c = curr / r;
        if (pairs.find(curr) == pairs.end())
            pairs[curr] = 0;
        pairs[curr] += cnt[c];
        if (c % r == 0) ans += pairs[c];
    }
    if (r == 1) {
        for (auto it = cnt.begin(); it != cnt.end(); it++) {
            k = it->second;
            ans += (k * (k - 1) * (k - 2)) / 6;
        }
    }
    cout << ans << endl;
}
