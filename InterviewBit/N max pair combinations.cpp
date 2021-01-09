using ll = long long;
using pii = pair<int, int>;
#define fi first
#define se second
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int n = A.size();
    vector<int> p(n, n - 1);
    priority_queue<pii> pq;
    for (int i = 0; i < n; i++)
        pq.push({A[i] + B[p[i]], i});
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        pii c = pq.top(); pq.pop();
        ans[i] = c.fi;
        pq.push({A[c.se] + B[--p[c.se]], c.se});
    }
    return ans;
}
