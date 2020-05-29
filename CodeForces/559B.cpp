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
string get(string s) {
    int n = s.size();
    if (n & 1) return s;
    string s1 = get(s.substr(0, n / 2));
    string s2 = get(s.substr(n / 2, n / 2));
    if (s1 < s2) return s1 + s2;
    return s2 + s1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a, b;
    cin >> a >> b;
    a = get(a);
    b = get(b);
    trace(a, b);
    puts((a == b) ? "YES" : "NO");
}
