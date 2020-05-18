class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int term = 0, ans = INT_MIN;
        for (int a : nums) {
            ans = max(ans, term + a);
            term = max(0, term + a);
        }
        return ans;
    }
};