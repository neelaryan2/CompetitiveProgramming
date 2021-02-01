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
#define rall(v) (v).rbegin(), (v).rend()

const int inf = 1e9 + 7;

struct mstack {
    stack<int> st;
    stack<ll> sum;
    mstack() {
        sum.push(0);
    }
    void push(int v) {
        st.push(v);
        sum.push(sum.top() + v);
    }
    void pop() {
        if (st.empty()) return;
        st.pop();
        sum.pop();
    }
    bool empty() { return st.empty(); }
};
template <class T>
struct mqueue {
    T left, right;
    mqueue() {}
    void push_front(int v) {
        left.push(v);
    }
    void push_back(int v) {
        right.push(v);
    }
    void pop_front() {
        if (left.empty()) {
            while (!right.empty()) {
                left.push(right.st.top());
                right.pop();
            }
        }
        if (!left.empty())
            left.pop();
    }
    ll sum() {
        return left.sum.top() + right.sum.top();
    }
};
void solve(int test) {
    int n, s;
    cin >> n >> s;
    vector<int> a(n), c(n);
    for (int& e : a) cin >> e;
    for (int& e : c) cin >> e;
    mqueue<mstack> q;
    ll weight = 0, ans = 0;
    int ptr = 0;
    for (int i = 0; i < n; i++) {
        weight += a[i];
        q.push_back(c[i]);
        while (ptr <= i && weight > s) {
            weight -= a[ptr++];
            q.pop_front();
        }
        ans = max(ans, q.sum());
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << '\n';
    }
}
