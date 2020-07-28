const int mod = 1e9 + 7;
int Solution::nTriang(vector<int> &A) {
    int n = A.size();
    sort(A.begin(), A.end());
    int ans = 0;
    for (int m = 1; m < n - 1; m++) {
        for (int l = 0, r = m + 1; l < m; l++) {
            while (r < n && A[r] < A[l] + A[m]) r++;
            ans += r - m - 1;
            if (ans >= mod) ans -= mod;
        }
    }
    return ans;
}
