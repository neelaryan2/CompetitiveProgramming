class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int& k : nums)
            if (k < 0 || k > n) k = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % (n + 1) == 0) continue;
            nums[nums[i] % (n + 1) - 1] += n + 1;
        }
        for (int i = 0; i < n; i++)
            if (nums[i] < (n + 1))
                return i + 1;
        return n + 1;
    }
};