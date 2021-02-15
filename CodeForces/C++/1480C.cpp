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

int ask(int x) {
    vector<int> v = {3, 2, 3};
    if (x < 0 || x >= v.size())
        return inf;
    cout << v[x] << endl;
    return v[x];
}
vector<int> arr;
int query(int x) {
    if (x < 0 || x >= arr.size())
        return inf;
    if (arr[x] == -1) {
        cout << "? " << (x + 1) << endl;
        cin >> arr[x];
        // arr[x] = ask(x);
    }
    return arr[x];
}
int findLocalMinima(int start, int end) {
    if (start == end - 1) return start;
    int mid = (start + end) / 2;
    trace(start, end, mid);
    if (mid - 2 < 0 && mid + 1 >= arr.size())
        return -1;
    if (query(mid - 2) > query(mid - 1) && query(mid - 1) < query(mid))
        return mid - 1;
    if (query(mid - 1) > query(mid - 2))
        return findLocalMinima(start, mid);
    else
        return findLocalMinima(mid, end);
}

void solve(int test) {
    int n;
    cin >> n;
    arr.assign(n, -1);
    if (n == 1) {
        cout << "! 1";
        return;
    }
    if (n == 2) {
        cout << "! ";
        cout << (query(0) > query(1) ? 2 : 1);
        return;
    }
    int ans = findLocalMinima(0, n);
    cout << "! " << (ans + 1);
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
