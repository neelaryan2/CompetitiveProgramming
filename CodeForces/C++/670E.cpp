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
using lt = list<int>::iterator;
void solve(int test) {
    int n, m, p;
    cin >> n >> m >> p;
    string s, q;
    cin >> s >> q;
    list<int> seq;
    stack<lt> st;
    vector<lt> pp(n);
    for (int i = 0; i < n; i++) {
        seq.push_back(i);
        auto it = prev(seq.end());
        if (s[i] == '(') {
            st.push(it);
        } else {
            assert(!st.empty());
            lt jt = st.top();
            st.pop();
            pp[*it] = jt;
            pp[*jt] = it;
        }
    }
    lt pointer = seq.begin();
    advance(pointer, p - 1);
    for (char c : q) {
        if (c == 'L') pointer--;
        if (c == 'R') pointer++;
        if (c == 'D') {
            lt oth = pp[*pointer];
            if (*oth < *pointer)
                swap(oth, pointer);
            lt nxt = ++oth;
            if (nxt == seq.end())
                nxt = prev(pointer);
            seq.erase(pointer, oth);
            pointer = nxt;
        }
    }
    for (int i : seq)
        cout << s[i];
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
