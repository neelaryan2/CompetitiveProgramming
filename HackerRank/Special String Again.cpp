#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pi;
typedef pair<long long, long long> pl;
typedef vector<int> vi;
#define forn(i, a, b) for (int i = (a); i <= (b); i++)
#define rfor(i, b, a) for (int i = (b); i >= (a); i--)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define rall(v) (v).rbegin(), (v).rend()
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define endl "\n"

long substrCount(int n, string str) {
    vector<char> s;
    vector<int> c;
    int cnt = 1;
    for (int i = 1; i < str.size(); i++)
        if (str[i] == str[i - 1]) cnt++;
        else {
            s.eb(str[i - 1]);
            c.eb(cnt); cnt = 1;
        }
    s.eb(str.back()); c.eb(cnt);
    long ans = 0;
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i - 1] == s[i + 1] && c[i] == 1)
            ans += min(c[i - 1], c[i + 1]);
    }
    for (int cn : c)
        ans += (1LL * cn * (cn + 1)) / 2;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
