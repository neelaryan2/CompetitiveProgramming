using ll = long long;
int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int i = 0, j = 0, k = 0, ans = INT_MAX;
    while (i < A.size() && j < B.size() && k < C.size()) {
        ll a = A[i], b = B[j], c = C[k];
        ll cur = max({abs(a - b), abs(b - c), abs(c - a)});
        if (cur < ans) ans = cur;
        int mn = min({a, b, c});
        if (mn == a) i++;
        else if (mn == b) j++;
        else k++;
    }
    return ans;
}
