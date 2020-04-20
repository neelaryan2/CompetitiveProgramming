#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<bool, bool>;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define endl '\n'
const ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    for (char c : s) {
        if (c == 'm' || c == 'w') {
            cout << 0 << endl;
            return 0;
        }
    }
    int n = s.size();
    vector<ll> dp(n + 1, 1);
    for (int i = 1; i < n; i++) {
        dp[i + 1] = dp[i];
        if (s[i] == s[i - 1] && (s[i] == 'n' || s[i] == 'u'))
            dp[i + 1] = (dp[i] + dp[i - 1]) % mod;
    }
    cout << dp[n] << endl;
}