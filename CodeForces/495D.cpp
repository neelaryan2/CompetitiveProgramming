#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
using ll = long long;
using pii = pair<int, int>;
using ppi = pair<int, pii>;
using vpi = vector<pii>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define runtime() (int)(1000 * ((double)clock()) / CLOCKS_PER_SEC)
using vi = vector<int>;
const int kMod = 1e9 + 7;
struct ModInt {
    long long n;
    ModInt(long long n = 0) : n(n % kMod) {}
    ModInt operator+(const ModInt& oth) { return n + oth.n; }
    ModInt operator-(const ModInt& oth) { return n - oth.n; }
    ModInt operator*(const ModInt& oth) { return n * oth.n; }
    long long get() { return n < 0 ? n + kMod : n; }
};
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
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    string tmp = t + '#' + s;
    vi lps = kmp(tmp);
    vector<ModInt> dp(n + 1, 0), dpp(n + 1, 0), dppp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (lps[i + m] == m) {
            if (i >= m) dp[i] = dppp[i - m] + i - m + 1;
        } else
            dp[i] = dp[i - 1];
        dpp[i] = dpp[i - 1] + dp[i];
        dppp[i] = dppp[i - 1] + dpp[i];
    }
    cout << dpp[n].get() << '\n';
}