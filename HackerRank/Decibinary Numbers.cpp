#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ratio>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

#define forn(i,x,y) for (int i = x; i < y; i++)
typedef long long ll;
const int N = 285112 + 5, B = 20;
ll dp[N][B], s[N] = {1};

void go(ll n, ll rank, ll pos, bool leading) {
    if (!pos) return;
    ll t = 1 << (pos - 1);
    ll s = 0;
    forn(i, 0, 10) {
        if (s + dp[n - i * t][pos - 1] <= rank)
            s += dp[n - i * t][pos - 1];
        else {
            if (!leading || i) cout << i;
            go(n - i * t, rank - s, pos - 1, leading && !i);
            return;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    forn(i, 0, B) dp[0][i] = 1;
    forn(i, 1, N) {
        s[i] = s[i - 1] + dp[i - 1][B - 1];
        forn(j, 1, B) {
            dp[i][j] = dp[i][j - 1];
            ll t = 1 << (j - 1);
            forn(k, 1, 10)
            if (t * k > i) break;
            else dp[i][j] += dp[i - t * k][j - 1];
        }
    }
    int T; cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        if (n == 1) {cout << "0\n"; continue;}
        int k = upper_bound(s, s + N, n) - s - 1;
        go(k, n - s[k], B, 1);
        cout << "\n";
    }
}