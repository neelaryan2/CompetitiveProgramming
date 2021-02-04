#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 2;
vector<vector<int>> ind(N);
vector<ll> a, nxt, prv;
ll get(vector<int> ids) {
    if (ids.size() == 1) {
        int x = ids[0];
        ll ans = 1LL * (x - prv[x]) * (nxt[x] - x);
        return ans;
    }
    ll l = ids[0], r = ids.back(), num = nxt[r] - prv[l] - 1;
    ll ans = (num * (num + 1)) / 2;
    for (int i = 1; i < ids.size(); i++) {
        num = ids[i] - ids[i - 1] - 1;
        ans -= (num * (num + 1)) / 2;
    }
    num = l - prv[l] - 1;
    ans -= (num * (num + 1)) / 2;
    num = nxt[r] - r - 1;
    ans -= (num * (num + 1)) / 2;
    return ans;
}
int main() {
    int n;
    cin >> n;
    a.resize(n);
    nxt.resize(n);
    prv.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ind[a[i]].push_back(i);
    }
    stack<int> st;
    ll ans = 0;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] > a[i])
            nxt[st.top()] = i, st.pop();
        st.push(i);
    }
    while (!st.empty())
        nxt[st.top()] = n, st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] > a[i])
            prv[st.top()] = i, st.pop();
        st.push(i);
    }
    while (!st.empty())
        prv[st.top()] = -1, st.pop();
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        auto sta = lower_bound(ind[a[i]].begin(), ind[a[i]].end(), i);
        auto en = upper_bound(ind[a[i]].begin(), ind[a[i]].end(), nxt[i]);
        vector<int> vec;
        for (auto it = sta; it != en; it++) {
            vis[*it] = true;
            vec.push_back(*it);
        }
        ans -= get(vec) * a[i];
    }
    // cout << ans << endl;
    vis.assign(n, false);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] < a[i])
            nxt[st.top()] = i, st.pop();
        st.push(i);
    }
    while (!st.empty())
        nxt[st.top()] = n, st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] < a[i])
            prv[st.top()] = i, st.pop();
        st.push(i);
    }
    while (!st.empty())
        prv[st.top()] = -1, st.pop();
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        auto sta = lower_bound(ind[a[i]].begin(), ind[a[i]].end(), i);
        auto en = upper_bound(ind[a[i]].begin(), ind[a[i]].end(), nxt[i]);
        vector<int> vec;
        for (auto it = sta; it != en; it++) {
            vis[*it] = true;
            vec.push_back(*it);
        }
        ans += get(vec) * a[i];
    }
    cout << ans << endl;
}