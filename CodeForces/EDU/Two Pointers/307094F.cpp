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
    int n, m;
    string s, let;
    cin >> n >> m >> s >> let;
    vector<int> cntl(26, 0), cur(26, 0);
    for (char ch : let)
        cntl[ch - 'a']++;

    auto bad = [&]() {
        for (int i = 0; i < 26; i++)
            if (cur[i] > cntl[i])
                return true;
        return false;
    };

    int ptr = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cur[s[i] - 'a']++;
        while (ptr <= i && bad())
            cur[s[ptr++] - 'a']--;
        ans += i - ptr + 1;
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
