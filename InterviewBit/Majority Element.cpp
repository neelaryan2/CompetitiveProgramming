int Solution::majorityElement(const vector<int> &A) {
    int n = A.size(), ans = -1, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == ans) cnt++;
        else if (cnt == 0) ans = A[i];
        else cnt--;
    }
    return ans;
}
