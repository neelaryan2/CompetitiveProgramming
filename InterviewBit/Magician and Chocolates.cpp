const int mod = 1e9 + 7;
int Solution::nchoc(int A, vector<int> &B) {
    multiset<int> s(B.begin(), B.end());
    int ans = 0;
    while (A--) {
        if (s.empty()) break;
        int val = *s.rbegin();
        s.erase(prev(s.end()));
        ans = (ans + val % mod) % mod;
        val /= 2;
        if (!val) continue;
        s.insert(val);
    }
    return ans;
}
