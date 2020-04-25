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
vector<int> lps;
void kmp(string const& s) {
    int n = s.size();
    lps.assign(n, 0);
    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];
        while (j > 0 && s[i] != s[j])
            j = lps[j - 1];
        if (s[i] == s[j]) j++;
        lps[i] = j;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    kmp(s);
    int n = s.size();
    int l = lps.back();
    vector<int> len(1, n);
    while (l != 0) {
        len.pb(l);
        l = lps[l - 1];
    }
    vector<int> amt(n + 1, 1);
    for (int i = n - 1; i >= 0; i--)
        amt[lps[i]] += amt[i + 1];
    reverse(all(len));
    cout << len.size() << endl;
    for (int i : len) {
        cout << i << " " << amt[i] << '\n';
    }
}