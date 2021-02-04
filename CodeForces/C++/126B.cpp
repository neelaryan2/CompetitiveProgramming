#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
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
    string s, r;
    cin >> s;
    r = s;
    reverse(all(r));
    vi blps = kmp(r);
    vi lps = kmp(s);
    reverse(all(blps));
    int n = s.size();
    int ind = 0, len = 0;
    for (int i = n - 1; i >= 0; i--) {
        int l = lps[i];
        int t = blps[i - l + 1];
        if (t == l && l > len) {
            ind = i - l + 1;
            len = l;
        }
    }
    string ans = s.substr(ind, len);
    if (len == 0) ans = "Just a legend";
    cout << ans << '\n';
}
