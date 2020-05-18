class Solution {
   public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;
        int neg = 1;
        if (x < 0) neg = -1, x *= -1;
        string y = to_string(x);
        std::reverse(y.begin(), y.end());
        try {
            return neg * stoi(y);
        } catch (...) {
            return 0;
        }
    }
};