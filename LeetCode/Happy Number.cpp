class Solution {
   public:
    int conv(int num) {
        int ret = 0;
        while (num) {
            int k = num % 10;
            ret += k * k;
            num /= 10;
        }
        return ret;
    }
    bool isHappy(int n) {
        map<int, bool> vis;
        while (true) {
            if (vis[n]) return false;
            vis[n] = true;
            n = conv(n);
            if (n == 1) return true;
        }
        return true;
    }
};