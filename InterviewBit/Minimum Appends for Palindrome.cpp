int kmp(string const& s) {
    int n = s.size();
    vector<int> lps(n, 0);
    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];
        while (j > 0 && s[i] != s[j])
            j = lps[j - 1];
        if (s[i] == s[j]) j++;
        lps[i] = j;
    }
    return lps.back();
}
int Solution::solve(string A) {
    string B = A;
    reverse(B.begin(), B.end());
    B += '$' + A;
    return A.size() - kmp(B);
}
