class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        multiset<int, greater<int>> s;
        for (int i = 0; i < n; i++) {
            s.insert(stones[i]);
        }
        while (s.size() > 1) {
            auto it = s.begin();
            auto it2 = it;
            it2++;
            s.insert((*it) - (*it2));
            s.erase(it);
            s.erase(it2);
        }
        return *s.begin();
    }
};