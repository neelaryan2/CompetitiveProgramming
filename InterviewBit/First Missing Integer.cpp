int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    for (int i = 0; i < n; i++)
        while (A[i] > 0 && A[i] <= n && A[i] != A[A[i] - 1]) 
            swap(A[i], A[A[i] - 1]);
    int k = 1;
    for (int i = 0; i < n; i++) 
        if (A[i] == k) k++;
    return k;
}
