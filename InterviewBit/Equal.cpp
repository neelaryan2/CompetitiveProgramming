using pii = pair<int, int>;
using ll = long long;
#define x first
#define y second
vector<int> Solution::equal(vector<int> &A) {
    int n = A.size();
    map<ll, vector<pii>> sums;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            sums[A[i] + A[j]].push_back({i, j});
    vector<int> ans = {n, n, n, n};
    for (auto v : sums) {
        pii p1 = v.y[0];
        for (int i = 1; i < v.y.size(); i++) {
            pii p2 = v.y[i];
            if (p1.y == p2.x || p1.x == p2.x || p2.y == p1.y) continue;
            vector<int> cur({p1.x, p1.y, p2.x, p2.y});
            ans = min(ans, cur);
        }
    }
    if (ans[0] == n) return {};
    return ans;
}
