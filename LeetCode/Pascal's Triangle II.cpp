class Solution {
   public:
    vector<int> getRow(int k) {
        using ll = long long;
        vector<int> ans(k + 1, 1);
        for (int i = 1; i <= k; i++) {
            int a = k - i + 1, b = i, g = __gcd(a, b);
            a /= g;
            b /= g;
            g = ans[i - 1] / b;
            g *= a;
            ans[i] = g;
        }
        return ans;
    }
};