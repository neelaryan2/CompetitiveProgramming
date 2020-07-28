#define all(v) (v).begin(), (v).end()
#define lb lower_bound
const int mod = 1e6 + 3;
int Solution::findRank(string A) {
    int n = A.size();
    vector<int> fact(n + 1, 1);
    for (int i = 1; i <= n; i++)
        fact[i] = (1LL * fact[i - 1] * i) % mod;
    vector<char> s(all(A));
    sort(all(s));
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int j = lb(all(s), A[i]) - s.begin();
        int res = (1LL * j * fact[n - i - 1]) % mod;
        ans = (ans + res) % mod;
        s.erase(s.begin() + j);
    }
    return ans;    
}
