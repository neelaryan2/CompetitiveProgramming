int Solution::diffPossible(const vector<int> &B, int k) {
    vector<int> A = B;
    sort(A.begin(), A.end());
    int n = A.size();
    for (int i = 0; i < n; i++) {
        int j = lower_bound(A.begin(), A.end(), A[i] - k) - A.begin();
        if (i != j && A[j] == A[i] - k)
            return 1;
    }
    return 0;
}
