class Solution {
    using ll = long long;
   public:
    int divide(ll dividend, ll divisor) {
        int sgn = 1;
        if (dividend < 0) sgn *= -1, dividend *= -1;
        if (divisor < 0) sgn *= -1, divisor *= -1;
        ll ans = 0, val = 0;
        for (int i = 31; i >= 0; i--) {
            if (val + (divisor << i) <= dividend) {
                val += (divisor << i);
                ans ^= (1LL << i);
            }
        }
        ans *= sgn;
        if (INT_MIN <= ans && ans <= INT_MAX)
            return ans;
        else
            return INT_MAX;
    }
};