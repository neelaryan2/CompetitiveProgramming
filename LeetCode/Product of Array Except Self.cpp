class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int left = 1, right = 1;
        for (int i = 0, j = n - 1; i < n; i++, j--) {
            ans[i] *= left;
            ans[j] *= right;
            left *= nums[i];
            right *= nums[j];
        }
        return ans;
    }
};