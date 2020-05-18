class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int mx = 0, n = nums.size();
        for (int i = 0; i <= min(mx, n - 1); i++)
            mx = max(mx, i + nums[i]);
        return (mx >= n - 1);
    }
};