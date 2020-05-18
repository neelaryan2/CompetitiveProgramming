class Solution {
   public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for (int n : nums) s.insert(n);
        if (s.size() < 3) return *s.rbegin();
        auto it = s.end();
        it--, it--, it--;
        return *it;
    }
};