int Solution::diffPossible(vector<int> &a, int k) {
    int n = a.size();
    if (a[0] > INT_MAX - k) return false;
    int i = lower_bound(a.begin(), a.end(), a[0] + k) - a.begin();
    for (; i < n; i++) {
        int j = lower_bound(a.begin(), a.end(), a[i] - k) - a.begin();
        if (j == i || a[j] + k != a[i]) continue;
        return true;
    }
    return false;
}
