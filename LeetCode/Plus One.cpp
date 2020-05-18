class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        int ind = digits.size() - 1;
        digits[ind]++;
        while (ind > 0 && digits[ind] == 10)
            digits[ind--] = 0, digits[ind]++;
        if (digits[0] == 10) {
            vector<int> ans(1, 1);
            digits[0] = 0;
            for (int i : digits) ans.emplace_back(i);
            return ans;
        }
        return digits;
    }
};