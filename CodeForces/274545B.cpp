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
void add(vector<int>& B, int i, int x) {
    int n = B.size();
    for (; i < n; i += i & (-i))
        B[i] = B[i] + x;
}
int sum(vector<int>& B, int i) {
    int sum = 0;
    for (; i > 0; i -= i & (-i))
        sum = sum + B[i];
    return sum;
}
int bit_search(vector<int>& B, int val) {
    int sum = 0, pos = 0, s = B.size();
    for (int i = log2(s); i >= 0; i--) {
        int d = (1 << i);
        if (pos + d < s && sum + B[pos + d] < val) {
            pos = pos + d;
            sum = sum + B[pos];
        }
    }
    return pos + 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n), B(n + 10, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        add(B, i + 1, 1);
    }
    for (int i = n - 1; i >= 0; i--) {
        int c = bit_search(B, i - a[i] + 1);
        add(B, c, -1);
        a[i] = c;
    }
    for (int i : a) cout << i << ' ';
    cout << '\n';
}
