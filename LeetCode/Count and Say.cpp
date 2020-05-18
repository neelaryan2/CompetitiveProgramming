class Solution {
   public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string tmp = countAndSay(n - 1);
        string ans = "";
        int cnt = 1;
        tmp += '@';
        for (int i = 1; i < tmp.size(); i++) {
            if (tmp[i] != tmp[i - 1]) {
                ans += to_string(cnt) + tmp[i - 1];
                cnt = 1;
            } else
                cnt++;
        }
        return ans;
    }
};