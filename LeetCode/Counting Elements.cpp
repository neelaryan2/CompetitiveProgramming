class Solution {
   public:
    int countElements(vector<int>& arr) {
        vector<int> cnt(1001, 0);
        int ans = 0;
        for (int a : arr) cnt[a]++;
        for (int i = 0; i < 1000; i++)
            if (cnt[i] != 0 && cnt[i + 1] != 0)
                ans += cnt[i];
        return ans;
    }
};