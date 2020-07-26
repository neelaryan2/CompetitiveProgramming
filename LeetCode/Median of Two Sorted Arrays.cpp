class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        auto findByPos = [&](int k) {
            int lo = max(0, k - n), hi = 1 + min(m, k), mid;
            while (lo < hi - 1) {
                mid = lo + (hi - lo) / 2;
                if (nums1[mid - 1] < nums2[k - mid])
                    lo = mid;
                else
                    hi = mid;
            }
            if (lo == 0) return nums2[k - 1];
            if (lo == k) return nums1[k - 1];
            return max(nums1[lo - 1], nums2[k - lo - 1]);
        };
        double ans = findByPos((m + n + 1) / 2) + findByPos(1 + (m + n) / 2);
        return ans / 2;
    }
};