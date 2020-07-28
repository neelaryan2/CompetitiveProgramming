const int mod = 1e9 + 7;
int Solution::cntBits(vector<int> &A) {
    int n = A.size(), ans = 0;
    for (int b = 31; b >=0; b--) {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if ((A[i] >> b) & 1) cnt++;
        ans += (2LL * cnt * (n - cnt)) % mod;
        ans %= mod;
    }
    return ans;
}
