class Solution {
   public:
    bool checkValidString(string s) {
        int sum = 0, cnt = 0;
        for (char c : s) {
            if (c == ')') sum--;
            if (c == '(') sum++;
            if (c == '*') cnt++;
            if (sum < 0) {
                if (cnt < -sum)
                    return false;
                else
                    cnt += sum, sum = 0;
            }
        }
        bool ans = (cnt >= abs(sum));
        reverse(s.begin(), s.end());
        sum = 0, cnt = 0;
        for (char c : s) {
            if (c == '(') sum--;
            if (c == ')') sum++;
            if (c == '*') cnt++;
            if (sum < 0) {
                if (cnt < -sum)
                    return false;
                else
                    cnt += sum, sum = 0;
            }
        }
        return ans || (cnt >= abs(sum));
    }
};