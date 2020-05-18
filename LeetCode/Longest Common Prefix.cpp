class Solution {
   public:
    void combine(string& ans, string& s) {
        int ind = 0;
        while (ind < min(s.size(), ans.size()) && ans[ind] == s[ind]) ind++;
        ans = ans.substr(0, ind);
    }
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string ans = strs.back();
        strs.pop_back();
        for (string& s : strs)
            combine(ans, s);
        return ans;
    }
};