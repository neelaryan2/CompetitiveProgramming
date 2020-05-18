class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                ans = max(ans, cnt);
                cnt = 0;
            } else
                cnt++;
        }
        return max(ans, cnt);
    }
};