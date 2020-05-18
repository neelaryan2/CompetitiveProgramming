class Solution {
   public:
    int romanToInt(string s) {
        int ans = 0, n = s.size();
        map<char, int> val;
        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;
        for (int i = 0; i < n; i++) {
            ans += val[s[i]];
            if (i == n - 1) continue;
            if (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) ans -= 2 * val[s[i]];
            if (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) ans -= 2 * val[s[i]];
            if (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')) ans -= 2 * val[s[i]];
        }
        return ans;
    }
};