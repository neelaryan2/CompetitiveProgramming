class Solution {
   public:
    bool isPalindrome(string s) {
        string tmp1, tmp2;
        for (char c : s) {
            c = tolower(c);
            if (isalpha(c) || isdigit(c))
                tmp1 += c;
        }
        tmp2 = tmp1;
        reverse(tmp2.begin(), tmp2.end());
        return tmp1 == tmp2;
    }
};