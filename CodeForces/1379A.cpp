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
const string st = "abacaba";
const int N = st.size();
bool check(string a) {
    for (int i = 0; i < N; i++) {
        if (a[i] == '?') continue;
        if (a[i] != st[i]) return false;
    }
    return true;
}
int counter(string s) {
    int cnt = 0, n = s.size();
    for (int i = 0; i + N - 1 < n; i++)
        if (s.substr(i, N) == st) cnt++;
    return cnt;
}
void solve(int test) {
    int n;
    string s;
    cin >> n >> s;
    if (counter(s) > 1) {
        cout << "No\n";
        return;
    }
    int ind = -1;
    for (int i = 0; i + N - 1 < n; i++) {
        if (!check(s.substr(i, N))) continue;
        string t = s;
        for (int j = i; j < i + N; j++)
            t[j] = st[j - i];
        if (counter(t) == 1) {
            ind = i;
            break;
        }
    }
    if (ind == -1) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    for (int j = ind; j < ind + N; j++)
        s[j] = st[j - ind];
    for (int j = 0; j < n; j++)
        if (s[j] == '?') s[j] = 'd';
    cout << s << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
