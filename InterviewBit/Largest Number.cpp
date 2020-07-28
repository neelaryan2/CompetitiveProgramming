string Solution::largestNumber(const vector<int> &A) {
    int n = A.size();
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        s[i] = to_string(A[i]);
    auto cmp = [](string a, string b) { return a + b > b + a; };
    sort(s.begin(), s.end(), cmp);
    string ans;
    for (string& t : s) ans += t;
    n = ans.size();
    int i = 0;
    while (i < n && ans[i] == '0') i++;
    if (i == n) i--;
    return ans.substr(i, n - i);
}
