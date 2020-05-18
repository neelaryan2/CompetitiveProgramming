class Solution {
   public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> cpy = arr;
        arr.clear();
        for (int i : cpy) {
            arr.push_back(i);
            if (arr.size() == cpy.size()) break;
            if (i == 0) arr.push_back(i);
            if (arr.size() == cpy.size()) break;
        }
    }
};