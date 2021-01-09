int kth(const vector<int> &A, const vector<int> &B, int k) {
    int m = A.size(), n = B.size();
    int lo = max(0, k - n), hi = min(m, k) + 1, mid;
    while (lo < hi - 1) {
        mid = lo + (hi - lo) / 2;
        if (A[mid - 1] <= B[k - mid]) lo = mid;
        else hi = mid;
    }
    if (lo == 0) return B[k - 1];
    if (lo == k) return A[k - 1];
    return max(A[lo - 1], B[k - lo - 1]);
}
double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int n = A.size(), m = B.size();
    int l = kth(A, B, (1 + m + n) / 2);
    int r = kth(A, B, 1 + (m + n) / 2);
    return ((double)l + r) / 2;
}
