int Solution::searchInsert(vector<int> &A, int B) {
    int n = A.size();
    int lo = 0, hi = n, mid;
    if (A[lo] >= B) return 0;
    while (lo < hi - 1) {
        mid = (lo + hi) / 2;
        if (A[mid] < B) lo = mid;
        else hi = mid;
    }
    return hi;
}
