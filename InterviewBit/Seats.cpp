const int mod = 1e7 + 3;
int Solution::seats(string A) {
    vector<int> p;
    for (int i = 0; i < A.size(); i++)
        if (A[i] == 'x') p.push_back(i);
    int n = p.size(), mid = n / 2, ans = 0;
    for (int i = n - 1; i >= 0; i--)
        ans = (ans + abs(p[mid] - (mid - i) - p[i])) % mod;
    return ans;
}
