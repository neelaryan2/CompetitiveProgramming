using pii = pair<int, int>;
using ll = long long;
#define x first
#define y second
vector<vector<int> > Solution::fourSum(vector<int> &a, int B) {
    int n = a.size();
    ll sum = B;
    sort(a.begin(), a.end());
    map<ll, vector<pii>> sums;
    map<pii, bool> done, ok;
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll cur = sum - a[i] - a[j];
            auto it = sums.find(cur);
            if (it == sums.end()) continue;
            for (pii p : sums[cur]) 
                ans.push_back({p.x, p.y, a[i], a[j]});
        }
        for (int j = 0; j < i; j++) {
            ll cur = a[i] + a[j];
            pii p = {a[j], a[i]};
            auto it = done.find(p);
            if (it == done.end()) {
                sums[cur].push_back(p);
                done[p] = true;
            }
        }
    }
    sort(ans.begin(), ans.end());
    int k = unique(ans.begin(), ans.end()) - ans.begin();
    ans.resize(k);
    return ans;
}
