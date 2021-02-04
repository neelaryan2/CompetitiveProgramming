/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
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
int get(vector<int>& B, int i) {
    if (i <= 0) return 0;
    int val = B[i];
    int z = i - (i & -i);
    for (--i; i != z; i -= i & (-i))
        val -= B[i];
    return val;
}
int bit_search(vector<int>& B, int val) {
    int sum = 0, pos = 0, s = B.size();
    for (int i = log2(s); i >= 0; i--) {
        int d = (1 << i);
        if (pos + d < s && sum + B[pos + d] < val) {
            pos += d;
            sum += B[pos];
        }
    }
    return pos + 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int& e : a) cin >> e;
    const int N = n + 10;
    vector<int> has(N, 0), ans(n);
    int last = 0;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (k == -1) {
            vector<int> vec;
            for (int j = 0; j < m; j++) {
                int p = bit_search(has, a[j]);
                if (p == N) break;
                vec.pb(p);
            }
            for (int j : vec)
                add(has, j, -1);
        } else {
            ans[last++] = k;
            add(has, last, 1);
        }
    }
    int p = bit_search(has, 1);
    if (p == N) {
        cout << "Poor stack!\n";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int b = get(has, i + 1);
        if (b == 0) continue;
        cout << ans[i];
    }
    cout << '\n';
}
