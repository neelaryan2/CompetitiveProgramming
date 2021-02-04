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
const int mod = 1e9 + 7;
void add(int& a, int b) {
    a = a + b;
    if (a >= mod) a -= mod;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> cnt(n + 1, 0);
    cnt[0] = 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        vector<int> div;
        for (int j = 1; j * j <= e; j++) {
            if (e % j) continue;
            if (j <= n) div.pb(j);
            if (e / j <= n) div.pb((e / j));
        }
        sort(rall(div));
        div.resize(distance(div.begin(), unique(all(div))));
        trace(div);
        for (int j : div) {
            add(cnt[j], cnt[j - 1]);
            add(ans, cnt[j - 1]);
        }
    }
    cout << ans << '\n';
}
