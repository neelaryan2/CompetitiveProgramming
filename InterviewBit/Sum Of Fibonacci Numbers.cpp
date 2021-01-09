using ll = long long;
using pii = pair<int, int>;
#define fi first
#define se second
int Solution::fibsum(int A) {
    vector<int> fib({0, 1});
    while (1) {
        int k = fib.size() - 1;
        ll cur = fib[k] + (ll)fib[k - 1];
        if (cur > INT_MAX) break;
        fib.push_back(cur);
    }
    int n = fib.size();
    map<int, int> vis;
    function<bool(int, int)> dfs = [&](int v, int d) {
        vis[v] = d;
        if (v == 0) return true;
        int i = upper_bound(fib.begin(), fib.end(), v) - fib.begin();
        for (i--; i >= 0; i--) {
            int u = v - fib[i];
            if (vis.find(u) != vis.end()) continue;
            if (dfs(u, d + 1)) return true;
        }
        return false;
    };
    dfs(A, 0);
    return vis[0];
}
