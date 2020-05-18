class Solution {
   public:
    int firstUniqChar(string s) {
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        for (int i = 0; i < s.size(); i++) {
            if (cnt[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};