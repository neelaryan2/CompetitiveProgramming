int Solution::bulbs(vector<int> &A) {
    int n = A.size(), ans = 0;
    for (int i = 0; i < n; i++)
        ans += (A[i] == (ans & 1));
    return ans;
}
