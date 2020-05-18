class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), ans = 0;
        if (n == 0) return ans;
        int mn = prices[0];
        for (int i = 1; i < n; i++) {
            ans = max(ans, prices[i] - mn);
            mn = min(mn, prices[i]);
        }
        return ans;
    }
};