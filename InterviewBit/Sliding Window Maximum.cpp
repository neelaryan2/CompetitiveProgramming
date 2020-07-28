vector<int> Solution::slidingMaximum(const vector<int> &A, int k) {
    deque<int> q;
    int n = A.size();
    for (int i = 0; i < min(k, n); i++) {
        while (!q.empty() && A[q.back()] <= A[i])
            q.pop_back();
        q.push_back(i);
    }
    vector<int> ans;
    for (int i = k; i < n; i++) {
        ans.push_back(A[q.front()]);
        if (i - k == q.front()) q.pop_front();
        while (!q.empty() && A[q.back()] <= A[i])
            q.pop_back();
        q.push_back(i);
    }
    ans.push_back(A[q.front()]);
    return ans;
}
