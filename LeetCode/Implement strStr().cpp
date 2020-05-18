class Solution {
   public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        for (int i = 0; i < haystack.size(); i++) {
            string tmp = haystack.substr(i, needle.size());
            if (tmp == needle) return i;
        }
        return -1;
    }
};