int Solution::singleNumber(const vector<int> &A) {
    int x = 0;
    for (int e : A) x ^= e;
    return x;
}
