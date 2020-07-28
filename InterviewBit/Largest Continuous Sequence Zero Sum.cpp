using ll = long long;
vector<int> Solution::lszero(vector<int> &A) {
    int n = A.size();
    map<ll, int> last;
    last[0] = -1;
    ll sum = 0;
    int len = 0, l = -1;
    for (int i = 0; i < n; i++) {
        sum += A[i];
        auto it = last.find(sum);
        if (it != last.end()) {
            if (i - it->second > len) {
                len = i - it->second;
                l = it->second + 1;
            }
        } else last[sum] = i;
    }
    vector<int> ans;
    for (int i = l; len--; i++)
        ans.push_back(A[i]);
    return ans;
}
