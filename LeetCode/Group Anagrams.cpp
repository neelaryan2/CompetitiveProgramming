class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        for (string s : strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            mp[tmp].emplace_back(s);
        }
        vector<vector<string>> ans;
        for (auto st : mp)
            ans.emplace_back(st.second);
        return ans;
    }
};