const int mod = 1e9 + 7;
using ll = long long;
int Solution::solve(int A) {
    int ans = 0, cnt = 0;
    for (int b = 31; b >= 0; b--) {
        if ((A >> b) & 1) {
            int cur = (1LL * cnt * (1 << b)) % mod;
            if (b > 0) cur += (1LL * b * (1 << (b - 1))) % mod;
            ans = (ans + cur % mod) % mod, cnt++;
        }
    }
    ans += cnt;
    return ans;
}
