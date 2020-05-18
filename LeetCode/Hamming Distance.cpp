class Solution {
   public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x ^ y);
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            ans += (x % 2 == y % 2);
            x /= 2;
            y /= 2;
        }
        return ans;
    }
};