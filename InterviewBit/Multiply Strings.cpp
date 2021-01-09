string Solution::multiply(string A, string B) {
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    int n = A.size(), m = B.size();
    vector<int> ans(n + m + 10, 0);
    for (int i = 0; i < m; i++) {
        for (int j = i, c = 0; (j < i + n) || c; j++) {
            if (j < i + n)
                ans[j] += (B[i] - '0') * (A[j - i] - '0');
            ans[j] += c;
            c = ans[j] / 10;
            ans[j] %= 10;
        }
    }
    while (!ans.empty() && ans.back() == 0) ans.pop_back();
    if (ans.empty()) ans.push_back(0);
    string ret;
    for (int i = ans.size() - 1; i >= 0; i--)
        ret += char(ans[i] + '0');
    return ret;
}
