class Solution {
   public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            int b1 = (n >> i) & 1;
            int b2 = (m >> i) & 1;
            if (b1 != b2) break;
            if (b1) ans ^= (1 << i);
        }
        return ans;
    }
};