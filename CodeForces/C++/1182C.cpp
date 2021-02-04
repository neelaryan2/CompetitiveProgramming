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

const string vowels = "aeiou";
const int inf = 1e9 + 7;
vector<string> words;
vector<int> cnt, last;
map<int, vi> valid;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    words.resize(n);
    cnt.assign(n, 0);
    last.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> words[i];
        for (int j = 0; j < words[i].size(); j++) {
            char ch = words[i][j];
            int vowel = 0;
            for (char c : vowels) {
                if (c == ch) break;
                vowel++;
            }
            if (vowel != 5) {
                cnt[i]++;
                last[i] = vowel;
            }
        }
        trace(words[i], cnt[i], last[i]);
        valid[cnt[i]].eb(i);
    }
    vector<int> v[vowels.size()], cur;
    vector<pii> ok1, ok2;
    for (auto p : valid) {
        trace(p.se);
        for (int i : p.se)
            v[last[i]].eb(i);
        for (int i = 0; i < vowels.size(); i++) {
            while (v[i].size() > 1) {
                int k = v[i].size() - 1;
                ok2.eb(v[i][k], v[i][k - 1]);
                v[i].pop_back();
                v[i].pop_back();
            }
            if (v[i].size()) {
                cur.eb(v[i][0]);
                v[i].pop_back();
            }
        }
        while (cur.size() > 1) {
            int k = cur.size() - 1;
            ok1.eb(cur[k], cur[k - 1]);
            cur.pop_back();
            cur.pop_back();
        }
        if (cur.size()) cur.pop_back();
    }
    trace(ok1, ok2);
    int t = min(ok1.size(), ok2.size());
    int ans = t + (ok2.size() - t) / 2;
    cout << ans << '\n';
    int ptr = 0;
    for (; ptr < t; ptr++) {
        cout << words[ok1[ptr].fi] << ' ' << words[ok2[ptr].fi] << '\n';
        cout << words[ok1[ptr].se] << ' ' << words[ok2[ptr].se] << '\n';
    }
    for (; ptr + 1 < ok2.size(); ptr += 2) {
        cout << words[ok2[ptr].fi] << ' ' << words[ok2[ptr+1].fi] << '\n';
        cout << words[ok2[ptr].se] << ' ' << words[ok2[ptr+1].se] << '\n';
    }
}
