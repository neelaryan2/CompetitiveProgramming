string binary(int n, int len) {
    string ans;
    while (len--) {
        ans += (n & 1) + '0';
        n >>= 1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int number(string s) {
    int n = 0;
    reverse(s.begin(), s.end());
    for (char c : s) {
        n <<= 1;
        if (c == '1') n++;
    }
    return n;
}
int Solution::solve(int A) {
    if (A == 1) return 1;
    int n = 1, cur = 1;
    while (cur < A) {
        A -= cur, n++;
        if (n & 1) cur <<= 1;
    }
    string s = binary(A - 1, (n - 1) / 2);
    string t = s.substr(0, s.size() - (n & 1));
    reverse(t.begin(), t.end());
    s = "1" + s + t + "1";
    return number(s);
}
