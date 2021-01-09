int Solution::mice(vector<int> &A, vector<int> &B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int n = A.size(), ans = -1;
    for (int i = 0; i < n; i++) 
        ans = max(ans, abs(A[i] - B[i]));
    return ans;
}
