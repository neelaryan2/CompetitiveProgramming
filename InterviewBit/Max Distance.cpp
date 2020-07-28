#include <numeric>
int Solution::maximumGap(const vector<int> &a) {
    int n = a.size();
    auto cmp = [&](int i, int j) { return a[i] < a[j]; };
    vector<int> b(n);
    iota(b.begin(), b.end(), 0);
    sort(b.begin(), b.end(), cmp);
    int mn = b[0], ans = 0;
    for (int i = 1; i < n; i++) {
        ans = max(ans, b[i] - mn);
        mn = min(mn, b[i]);
    }
    return ans;
}
