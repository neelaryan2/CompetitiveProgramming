class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int ind = 0, n = nums.size();
        if (n <= 1) return n;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) continue;
            nums[++ind] = nums[i];
        }
        return ind + 1;
    }
};