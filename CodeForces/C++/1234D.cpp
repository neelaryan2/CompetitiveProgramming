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
    int n = s.size();
    int q;
    cin >> q;
    set<int> sex[26];
    for (int i = 0; i < n; i++)
        sex[s[i] - 'a'].insert(i);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            int old = s[--pos] - 'a';
            sex[old].erase(pos);
            sex[c - 'a'].insert(pos);
            s[pos] = c;
        } else {
            int l, r;
            cin >> l >> r;
            --l, --r;
            int cnt = 0;
            for (int i = 0; i < 26; i++) {
                auto it = sex[i].lower_bound(l);
                if (it == sex[i].end()) continue;
                if (*it <= r) cnt++;
            }
            cout << cnt << '\n';
        }
    }
}
