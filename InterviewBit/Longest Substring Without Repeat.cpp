int Solution::lengthOfLongestSubstring(string A) {
    int n = A.size();
    vector<int> id(256, n + 1), nxt(n);
    for (int i = n - 1; i >= 0; i--) {
        nxt[i] = id[A[i]];
        id[A[i]] = i;
    }
    multiset<int> s;
    int ans = 0, l = 0;
    for (int i = 0; i < n; i++) {
        s.insert(nxt[i]);
        while (l <= i && *s.begin() <= i)
            s.erase(s.find(nxt[l++]));
        ans = max(ans, i - l + 1);
    }
    return ans;
}
