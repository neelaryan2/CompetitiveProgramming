#include <numeric>
using ll = long long;
string Solution::getPermutation(int n, int k) {
    vector<int> fact(n, -1);
    fact[0] = 1;
    for (int i = 1; i < n; i++) {
        ll cur = 1LL * fact[i - 1] * i;
        if (cur > k) break;
        fact[i] = cur;
    }
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    string ans; k--;
    for (int i = n - 1; i >= 0; i--) {
        int q = (fact[i] == -1) ? 0 : k / fact[i];
        k = (fact[i] == -1) ? k : k % fact[i];
        ans += to_string(v[q]);
        v.erase(v.begin() + q);
    }
    return ans;
}
