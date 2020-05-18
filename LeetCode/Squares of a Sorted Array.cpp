class Solution {
   public:
    vector<int> sortedSquares(vector<int>& A) {
        for (int& a : A) a *= a;
        sort(A.begin(), A.end());
        return A;
    }
};