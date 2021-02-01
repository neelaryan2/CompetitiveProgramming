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

const int N = (1 << 10);
using bit = bitset<N>;

template <typename T>
struct mstack {
    stack<T> st;
    stack<bit> sums;
    mstack() {
        bit tmp;
        tmp.set(0);
        sums.push(tmp);
    }
    void push(T v) {
        st.push(v);
        bit tmp = sums.top();
        for (T i = N - 1; i >= 0; i--)
            if (i + v < N && tmp.test(i))
                tmp.set(i + v);
        sums.push(tmp);
    }
    void pop() {
        st.pop();
        sums.pop();
    }
    bool empty() { return st.empty(); }
};
template <typename T>
struct mqueue {
    mstack<T> left, right;
    mqueue() {}
    void push_front(T v) {
        left.push(v);
    }
    void push_back(T v) {
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
    bool check(T s) {
        bit lef = left.sums.top();
        bit righ = right.sums.top();
        for (int i = 0; i <= s; i++)
            if (lef.test(i) && righ.test(s - i))
                return true;
        return false;
    }
};

void solve(int test) {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int& e : a) cin >> e;

    mqueue<short int> q;
    int ptr = 0, ans = n + 1;

    for (int i = 0; i < n; i++) {
        q.push_back(a[i]);
        while (ptr <= i && q.check(s)) {
            ans = min(ans, i - ptr + 1);
            q.pop_front(), ptr++;
        }
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
