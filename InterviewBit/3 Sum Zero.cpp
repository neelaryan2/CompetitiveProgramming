using ll = long long;
vector<vector<int> > Solution::threeSum(vector<int> &B) {
    int n = B.size();
    sort(B.begin(), B.end());
    vector<ll> A(B.begin(), B.end());
    set<vector<int>> ans; 
    for (int i = 0; i < n; i++) {
        int l = 0;
        ll sum = -A[i];
        for (int r = n - 1; r > i; r--) {
            while (l < i && A[l] + A[r] < sum)
                l++;
            if (l < i && A[l] + A[r] == sum)
                ans.insert({A[l], A[i], A[r]});
            while (l < i && A[l] + A[r] == sum) 
                l++;
        }
    }
    vector<vector<int>> res(ans.begin(), ans.end());
    return res;
}
