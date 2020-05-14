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
const int p1 = 31, p2 = 53;
const int mod = 1e9 + 9;
vi kmp(string const& s) {
    int n = s.size();
    vector<int> lps(n, 0);
    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];
        while (j > 0 && s[i] != s[j])
            j = lps[j - 1];
        if (s[i] == s[j]) j++;
        lps[i] = j;
    }
    return lps;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string t, s, e;
    cin >> t >> s >> e;
    vector<pii> vec;
    string tmp = s + "#" + t + "@" + e;
    string tmpr = s + "#" + t + "@" + e;
    reverse(all(tmpr));
    vi lps = kmp(tmp);
    vi blps = kmp(tmpr);
    reverse(all(blps));

    int n = s.size(), m = e.size(), k = t.size();
    pii ehs = {0, 0};
    ll pw1 = 1, pw2 = 1;
    for (int j = 0; j < m; j++) {
        ehs.fi = (ehs.fi + pw1 * e[j]) % mod;
        ehs.se = (ehs.se + pw2 * e[j]) % mod;
        pw1 = (pw1 * p1) % mod;
        pw2 = (pw2 * p2) % mod;
    }
    for (int i = n + 1; i < k + n + 1; i++) {
        if (lps[i] != n) continue;
        pii hs = {0, 0};
        ll pw1 = 1, pw2 = 1;
        for (int j = i - n + 1; j < i - min(n, m) + 1; j++) {
            hs.fi = (hs.fi + pw1 * tmp[j]) % mod;
            hs.se = (hs.se + pw2 * tmp[j]) % mod;
            pw1 = (pw1 * p1) % mod;
            pw2 = (pw2 * p2) % mod;
        }
        for (int j = i - min(n, m) + 1; j < k + n + 1; j++) {
            hs.fi = (hs.fi + pw1 * tmp[j]) % mod;
            hs.se = (hs.se + pw2 * tmp[j]) % mod;
            pw1 = (pw1 * p1) % mod;
            pw2 = (pw2 * p2) % mod;
            if (blps[j] != m) continue;
            pii nhs;
            nhs.fi = (hs.fi + pw1 * ehs.fi) % mod;
            nhs.se = (hs.se + pw2 * ehs.se) % mod;
            vec.pb(nhs);
        }
    }
    sort(all(vec));
    int ans = unique(all(vec)) - vec.begin();
    cout << ans << '\n';
}
