vector<int> nxtGreater(vector<int>& a) {
    stack<int> st;
    int n = a.size();
    vector<int> nxt(n, -1);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] <= a[i])
            nxt[st.top()] = i, st.pop();
        st.push(i);
    }
    return nxt;
}
vector<int> nxtStrictGreater(vector<int>& a) {
    stack<int> st;
    int n = a.size();
    vector<int> nxt(n, -1);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] < a[i])
            nxt[st.top()] = i, st.pop();
        st.push(i);
    }
    return nxt;
}
int Solution::trap(const vector<int> &a) {
    vector<int> A = a;
    int n = A.size();
    vector<int> nxt = nxtGreater(A);
    int ans = 0;
    for (int i = 0; nxt[i] != -1; i = nxt[i])
        for (int j = i; j < nxt[i]; j++)
            ans += A[i] - A[j];
    reverse(A.begin(), A.end());
    nxt = nxtStrictGreater(A);
    for (int i = 0; nxt[i] != -1; i = nxt[i])
        for (int j = i; j < nxt[i]; j++)
            ans += A[i] - A[j];
    return ans; 
}
