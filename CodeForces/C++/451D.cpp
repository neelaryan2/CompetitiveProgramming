#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int n = s.size(), c, p;
    int cnt[2][2];
    memset(cnt, 0, sizeof(cnt));
    ll odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        c = s[i] - 'a';
        p = i & 1;
        cnt[c][p]++;
        odd += cnt[c][p];
        even += cnt[c][1 - p];
    }
    cout << even << ' ' << odd << '\n';
}