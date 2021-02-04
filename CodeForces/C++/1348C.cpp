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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(27, 0);
    for (char c : s) cnt[c - 'a']++;
    sort(all(s));
    bool f = true;
    string ans;
    for (int i = 0; i < k; i++)
        if (s[i] != s[0])
            f = false;
    if (f) {
        ans = s.substr(k - 1, 1);
        if (k == n) {
            cout << ans << '\n';
            return;
        }
        for (int i = k; i < n; i++)
            if (s[i] != s[k])
                f = false;
        if (f) {
            int len = (n - 1) / k;
            ans = ans + s.substr(n - len, len);
        } else {
            ans = s.substr(k - 1, n - k + 1);
        }
    } else
        ans = s.substr(k - 1, 1);
    cout << ans << '\n';
    // if (n == k) {
    //     cout << s[k - 1] << '\n';
    //     return;
    // }
    // bool flag = true;
    // char c = s[k];
    // for (int i = k; i < n; i++)
    //     if (s[i] != c)
    //         flag = false;
    // if (flag) {
    //     cout<<s[k - 1];
    //     string ans;
    //     for (int i = 0; i < (n/k - 1); i++)
    //         ans += s[k];
    //     cout << ans << '\n';
    //     return;
    // }
    // for (int i = k - 1; i < n; i++)
    //     cout << s[i];
    // cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
