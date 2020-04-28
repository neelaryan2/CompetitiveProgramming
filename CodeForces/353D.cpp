#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 502;
using vi = bitset<N>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define sz(v) int((v).size())

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    reverse(all(s));
    while (s.back() == 'F') s.pop_back();
    reverse(all(s));
    vector<int> t, d;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'F') {
            d.pb(abs(i - cnt++));
        }
    }
    int n = d.size();
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    t.assign(n, 0);
    t[0] = d[0];
    for (int i = 1; i < n; i++) {
        t[i] = max(t[i - 1] + 1, d[i]);
    }
    cout << t.back() << endl;
}