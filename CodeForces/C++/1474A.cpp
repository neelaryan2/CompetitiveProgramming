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

void solve(int test) {
    int n;
    string str;
    cin >> n >> str;
    trace(n, str);
    for (int i = 0; i < n; i++) {
        int count = 1, id = i;
        while (i < n - 1 && str[i] == str[i + 1])
            count++, i++;
        if (str[i] == '1') {
            for (int j = id + 1; j < id + count; j += 2)
                str[j] = '0';
        } else if (id > 0 && str[id - 1] == '0') {
            for (int j = id + 1; j < id + count; j += 2)
                str[j] = '1';
        } else {
            for (int j = id; j < id + count; j += 2)
                str[j] = '1';
        }
    }
    cout << str;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << '\n';
    }
}
