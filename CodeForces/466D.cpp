#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ppi = pair<int, pii>;
using vi = vector<int>;
using vpi = vector<pii>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

const int kMod = 1e9 + 7;
struct ModInt {
    long long n;
    ModInt(long long n = 0) : n(n % kMod) {}
    ModInt operator+(const ModInt& oth) { return n + oth.n; }
    ModInt operator-(const ModInt& oth) { return n - oth.n; }
    ModInt operator*(const ModInt& oth) { return n * oth.n; }
    long long get() { return n < 0 ? n + kMod : n; }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, h;
    cin >> n >> h;
    vector<int> a(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = h - a[i];
        if (a[i] < 0) {
            cout << "0\n";
            return 0;
        }
    }
    ModInt ans = 1;
    for (int i = 1; i <= n + 1; i++) {
        if (a[i] == a[i - 1] - 1 || a[i] == a[i - 1])
            ans = ans * (a[i] + 1);
        if (abs(a[i] - a[i - 1]) >= 2) {
            cout << "0\n";
            return 0;
        }
    }
    cout << ans.get() << '\n';
}