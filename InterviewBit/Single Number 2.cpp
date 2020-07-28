int Solution::singleNumber(const vector<int> &A) {
    int ans = 0;
    for (int b = 31; b >= 0; b--) {
        int cnt = 0;
        for (int e : A)
            if ((e >> b) & 1) cnt++;
        if (cnt % 3) ans ^= (1 << b);
    }
    return ans;
}
