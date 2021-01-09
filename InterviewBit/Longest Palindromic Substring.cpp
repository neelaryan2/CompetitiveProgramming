string Solution::longestPalindrome(string A) {
    int n = A.size(), id = -1, len = -1;
    for (int i = 0; i < n; i++) {
        for (int o : {0, 1}) {
            int l = i - o, r = i + 1, cur = o;
            while (l >= 0 && r < n && A[l] == A[r])
                l--, r++, cur++;
            cur = 2 * cur - o;
            if (cur > len)
                len = cur, id = l + 1;
        }
    }
    return A.substr(id, len);
}
