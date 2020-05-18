class Solution {
   public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int n : nums) {
            int cnt = 0;
            while (n) cnt++, n /= 10;
            if (cnt % 2 == 0) ans++;
        }
        return ans;
    }
};