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
    stack<ll> st, gst;
    mstack() {
        gst.push(0);
    }
    void push(ll v) {
        st.push(v);
        gst.push(__gcd(gst.top(), v));
    }
    void pop() {
        if (st.empty()) return;
        st.pop();
        gst.pop();
    }
    bool empty() { return st.empty(); }
};
template<class T>
struct mqueue {
    T left, right;
    mqueue() {}
    void push_front(ll v) {
        left.push(v);
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
    void push_back(ll v) {
        right.push(v);
    }
    ll gcd() {
        return __gcd(left.gst.top(), right.gst.top());
    }
};
void solve(int test) {
    int n; cin >> n;
    vector<ll> a(n);
    for (ll&e : a) cin >> e;
    mqueue<mstack> q;
    int ptr = 0, ans = n + 1;
    for (int i = 0; i < n; i++) {
        while (ptr < n && q.gcd() != 1)
            q.push_back(a[ptr++]);
        if (q.gcd() == 1)
            ans = min(ans, ptr - i);
        q.pop_front();
    }
    if (ans == n + 1) ans = -1;
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
