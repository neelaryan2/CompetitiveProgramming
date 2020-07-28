vector<int> Solution::plusOne(vector<int> &A) {
    reverse(A.begin(), A.end());
    int n = A.size(), i = 0;
    while (i < n && ++A[i] == 10) A[i++] = 0;
    if (i == n) A.push_back(1);
    while (A.back() == 0) A.pop_back();
    reverse(A.begin(), A.end());
    return A;
}
