#define x first
#define y second
using ll = long long;
using pii = pair<int, int>;
vector<ll> getLine(pii p1, pii p2) {
    vector<ll> ret(3, 0);
    ret[0] = p2.y - p1.y;
    ret[1] = p1.x - p2.x;
    ret[2] = 1LL * p1.x * ret[0] + 1LL * p1.y * ret[1];
    ll g = __gcd(ret[0], ret[1]);
    g = __gcd(g, ret[2]);
    ret[0] /= g, ret[1] /= g, ret[2] /= g;
    return ret;
}
int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    int n = A.size(), ans = 0;
    if (n <= 2) return n;
    for (int i = 0; i < n; i++) {
        pii p1 = {A[i], B[i]};
        map<vector<ll>, int> cnt;
        cnt[{0, 0, 0}] = 0;
        int rep = 0;
        for (int j = 0; j < n; j++) {
            pii p2 = {A[j], B[j]};
            if (p1 == p2) { rep++; continue; }
            vector<ll> line = getLine(p1, p2);
            auto it = cnt.find(line);
            if (it == cnt.end()) cnt[line] = 1;
            else it->second++;
        }
        for (auto p : cnt)
            ans = max(ans, p.second + rep);
    }
    return ans;
}
