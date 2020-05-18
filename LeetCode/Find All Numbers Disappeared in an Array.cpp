class Solution {
   public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(n + 1);
        for (int i = 0; i < n; i++) {
            int x = abs(nums[i]);
            nums[x] = -abs(nums[x]);
        }
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (nums[i] > 0)
                ans.push_back(i);
        }
        return ans;
    }
};