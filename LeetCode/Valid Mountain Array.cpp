class Solution {
   public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        if (n < 3) return false;
        int ind = max_element(A.begin(), A.end()) - A.begin();
        if (ind == 0 || ind == n - 1) return false;
        for (int i = 1; i <= ind; i++)
            if (A[i] <= A[i - 1]) return false;
        for (int i = n - 2; i >= ind; i--)
            if (A[i + 1] >= A[i]) return false;
        return true;
    }
};