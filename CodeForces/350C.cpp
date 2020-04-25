#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define fi first
#define se second
#define pii pair<int, int>
void print(int x, int y) {
    if (x != 0) {
        cout << "1 " << abs(x) << " ";
        cout << (x < 0 ? "L" : "R") << '\n';
    }
    if (y != 0) {
        cout << "1 " << abs(y) << " ";
        cout << (y < 0 ? "D" : "U") << '\n';
    }
    cout << 2 << '\n';
    if (x != 0) {
        cout << "1 " << abs(x) << " ";
        cout << (x > 0 ? "L" : "R") << '\n';
    }
    if (y != 0) {
        cout << "1 " << abs(y) << " ";
        cout << (y > 0 ? "D" : "U") << '\n';
    }
    cout << 3 << '\n';
}
bool cmp(pii a, pii b) {
    if (abs(a.fi) != abs(b.fi))
        return abs(a.fi) < abs(b.fi);
    else
        return abs(a.se) < abs(b.se);
}
map<int, int> cnt;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pii> arr(n);
    int cnt = 0;
    for (pii& p : arr) {
        cin >> p.fi >> p.se;
        if (p.fi == 0 || p.se == 0)
            cnt++;
    }
    sort(arr.begin(), arr.end(), cmp);
    cout << (6 * n - 2 * cnt) << endl;
    for (pii& p : arr) {
        print(p.fi, p.se);
    }
}