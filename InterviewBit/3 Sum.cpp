using ll = long long;
int Solution::threeSumClosest(vector<int> &B, int T) {
    int n = B.size();
    sort(B.begin(), B.end());
    vector<ll> A(B.begin(), B.end());
    ll sum = T, gap = INT_MAX, ans = -1;
    auto update = [&](ll cur) {
        ll c = abs(cur - sum);
        if (c > gap) return;
        gap = c, ans = cur;
    };
    for (int i = 0; i < n; i++) {
        for (int r = n - 1, l = 0; r > i; r--) {
            while (l < i && A[l] + A[r] + A[i] < sum) {
                update(A[l++] + A[r] + A[i]);
            }
            if (l < i) update(A[l] + A[r] + A[i]);
        }
    }
    return ans;
}
