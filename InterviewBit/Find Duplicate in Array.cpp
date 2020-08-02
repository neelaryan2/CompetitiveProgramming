int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size() - 1;
    vector<int> cnt(n, 0);
    for (int e : A) 
        if (++cnt[e - 1] > 1)
            return e;
    return -1;
}