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
const int len = 1000;

string fromInt(int x, int b) {
    string ret;
    for (int i = b - 1; i >= 0; i--) {
        if ((x >> i) & 1)
            ret += '1';
        else
            ret += '0';
    }
    return ret;
}
int get(string& s) {
    for (int i = 1; i <= 10; i++) {
        for (int k = 0; k < (1 << i); k++) {
            string t = fromInt(k, i);
            if (s.find(t) == string::npos)
                return i - 1;
        }
    }
    assert(false);
}
void compress(string& s) {
    if (s.size() > len)
        s.erase(len / 2, s.size() - len);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<string> sex(n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        cin >> sex[i];
        ans[i] = get(sex[i]);
    }
    int m;
    cin >> m;
    cerr << fromInt(2, 3) << endl;
    while (m--) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        string c = sex[a] + sex[b];
        compress(c);
        int cur = get(c);
        cur = max({cur, ans[a], ans[b]});
        ans.pb(cur), sex.pb(c);
        cout << cur << '\n';
    }
}
