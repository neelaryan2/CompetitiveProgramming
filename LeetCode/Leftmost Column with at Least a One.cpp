/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
   public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int n = dim[0], m = dim[1];
        int ans = m;
        for (int i = 0; i < n; i++) {
            int lo = 0, hi = m - 1, mid;
            if (binaryMatrix.get(i, hi) == 0) continue;
            if (binaryMatrix.get(i, lo) == 1) {
                ans = 0;
                break;
            }
            while (lo < hi - 1) {
                mid = lo + (hi - lo) / 2;
                if (binaryMatrix.get(i, mid))
                    hi = mid;
                else
                    lo = mid;
            }
            ans = min(ans, hi);
        }
        return (ans == m) ? -1 : ans;
    }
};