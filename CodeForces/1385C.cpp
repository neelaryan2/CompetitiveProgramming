#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
vector<int> prevGreater(vector<int>& a) {
    int n = a.size();
    stack<int> s;
    vector<int> ans(n, -1);
    s.push(0);
    for (int i = 1; i < n; i++) {
        while (!s.empty() && a[s.top()] <= a[i])
            s.pop();
        if (!s.empty()) ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> nextGreater(vector<int>& a) {
    int n = a.size();
    stack<int> s;
    vector<int> ans(n, -1);
    s.push(0);
    for (int i = 1; i < n; i++) {
        while (!s.empty() && a[s.top()] < a[i])
            ans[s.top()] = i, s.pop();
        s.push(i);
    }
    return ans;
}
void solve(int test) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    vector<int> prv = prevGreater(a);
    vector<int> nxt = nextGreater(a);
    int mx = -1;
    for (int i = 0; i < n; i++) {
        if (nxt[i] == -1) continue;
        mx = max(mx, prv[i]);
    }
    cout << mx + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
