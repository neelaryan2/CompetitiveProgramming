class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size() - 1;
        for (int i = 0; i <= n; i++) {
            while (n >= 0 && nums[n] == val) n--;
            if (i >= n) break;
            if (nums[i] == val) swap(nums[i], nums[n--]);
        }
        return n + 1;
    }
};