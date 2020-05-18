class Solution {
   public:
    string getPermutation(int n, int k) {
        vector<int> fact(n + 1, 1);
        set<int> s;
        k--;
        for (int i = 1; i <= n; i++) {
            fact[i] = i * fact[i - 1];
            s.insert(i);
        }
        string ans;
        while (!s.empty()) {
            int a = fact[s.size() - 1];
            auto it = s.begin();
            advance(it, k / a);
            k %= a;
            ans += char((*it) + '0');
            s.erase(it);
        }
        return ans;
    }
};