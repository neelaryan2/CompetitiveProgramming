class Solution {
   public:
    Solution(vector<int>& nums) {
        mydeck = nums;
    }
    vector<int> reset() {
        return mydeck;
    }
    vector<int> shuffle() {
        vector<int> res(mydeck);
        //srand(time(NULL));
        for (int i = res.size() - 1; i >= 0; i--) {
            int j = rand() % (i + 1);
            swap(res[i], res[j]);
        }
        return res;
    }

   private:
    vector<int> mydeck;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */