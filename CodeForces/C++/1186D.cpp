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
// clang-format off
char wgc(char& ch) { while (isspace(ch = getchar())); return ch; }
char gc(char& ch) { return ch = getchar(); }
int readint() {
    int x = 0; bool neg = false; char ch;
    if (wgc(ch) == '-') neg = true, wgc(ch);
    do { x = x * 10 + ch - '0'; } while (isdigit(gc(ch)));
    return (neg ? -x : x);
}
ld readdbl() {
    ld x = 0, f = 1; bool neg = false; char ch;
    if (wgc(ch) == '-') neg = true, wgc(ch);
    do { x = x * 10 + ch - '0'; } while (isdigit(gc(ch)));
    while (isdigit(gc(ch))) f /= 10, x += f * (ch - '0'); 
    return (neg ? -x : x);
}
// clang-format on
void solve(int test) {
    int n = readint();
    trace(n);
    vector<int> a(n), mark(n, false);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        ld e = readdbl();
        a[i] = int(e);
        if (a[i] == e) mark[i] = true;
        else if (e < 0) a[i]--;
        sum += a[i];
    }
    for (int i = 0; i < n; i++) {
        if (mark[i]) continue;
        if (sum == 0) break;
        a[i]++, sum++;
    }
    assert(sum == 0);
    for (int& c : a)
        cout << c << '\n';
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
        cout << "\n";
    }
}
