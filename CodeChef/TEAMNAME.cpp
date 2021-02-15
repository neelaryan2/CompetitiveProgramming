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
const int A = 26;

void solve(int test) {
    int n;
    cin >> n;
    set<string> st;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        st.insert(s[i]);
    }
    bool unfun[n][A];
    for (int i = 0; i < n; i++) {
        string cur = s[i];
        for (int j = 0; j < A; j++) {
            cur[0] = j + 'a';
            unfun[i][j] = (st.find(cur) == st.end());
        }
    }
    int cnt[A][A];
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; i++) {
    	int c = s[i][0] - 'a';
        for (int j = 0; j < A; j++)
            if (unfun[i][j])
                cnt[c][j]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
    	int c = s[i][0] - 'a';
        for (int j = 0; j < A; j++)
            if (unfun[i][j])
                ans += cnt[j][c];
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << '\n';
    }
}
