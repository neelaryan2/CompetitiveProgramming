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
    int n, q;
    cin >> n >> q;
    vector<int> cnt(26, 0);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        cnt[c - 'a']++;
    }
    for (int _ = 0; _ < q; _++) {
        int a;
        cin >> a;
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            int tmp = min(a, cnt[i]);
            ans += cnt[i] - tmp;
        }
        cout << ans << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
