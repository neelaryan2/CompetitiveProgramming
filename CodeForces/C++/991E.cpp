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
#define rall(v) (v).rbegin(), (v).rend()

const int inf = 1e9 + 7;

void solve(int test) {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> tot(10, 0);
    for (char ch : s)
        tot[ch - '0']++;
    set<string> st;
    vector<ll> fact(20, 1);
    for (int i = 1; i < 20; i++)
        fact[i] = fact[i - 1] * i;
    for (int i = 0; i < (1 << n); i++) {
        string c;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) c += s[j];
        }
        sort(all(c));
        st.insert(c);
    }
    ll ans = 0;
    for (string c : st) {
        vector<int> cnt(10, 0);
        for (char ch : c)
            cnt[ch - '0']++;
        bool bad = false;
        for (int i = 0; i < 10; i++)
            if (tot[i] > 0 && cnt[i] == 0)
                bad = true;
        if (bad) continue;
        int k = c.size(), c0 = cnt[0];
        ll cur = fact[k - c0];
        for (int i = 1; i < 10; i++)
            cur /= fact[cnt[i]];
        ll tmp = fact[k - 1] / (fact[c0] * fact[k - 1 - c0]);
        ans += cur * tmp;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << '\n';
    }
}
