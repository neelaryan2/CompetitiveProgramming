using ll = long long;
vector<int> Solution::twoSum(const vector<int> &A, int B) {
    int n = A.size();
    map<ll, int> sums;
    for (int i = 0; i < n; i++) {
        auto it = sums.find(B - A[i]);
        if (it != sums.end())
            return {it->second, i + 1};
        it = sums.find(A[i]);
        if (it == sums.end())
            sums[A[i]] = i + 1;
    }
    return {};
}
