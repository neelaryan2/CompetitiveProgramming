class Solution {
   public:
    bool checkIfExist(vector<int>& arr) {
        map<int, int> cnt;
        for (int a : arr)
            cnt[a]++;
        for (int a : arr) {
            cnt[a]--;
            if (cnt[2 * a]) return true;
            cnt[a]++;
        }
        return false;
    }
};