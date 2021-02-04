#include <bits/stdc++.h>
using namespace std;

const int kMod = 1e9 + 7;
struct ModInt {
    long long n;
    ModInt(long long n = 0) : n(n % kMod) {}
    ModInt operator+(const ModInt& oth) { return n + oth.n; }
    ModInt operator-(const ModInt& oth) { return n - oth.n; }
    ModInt operator*(const ModInt& oth) { return n * oth.n; }
    long long get() { return n < 0 ? n + kMod : n; }
};
const int n = 1e5 + 5;
ModInt dp[n];

int main() {
    int t, k;
    cin >> t >> k;
    for (int i = 0; i < k; i++) {
        dp[i] = 1;
    }
    for (int i = k; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - k];
    }
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i] + dp[i - 1];
    }
    while (t--) {
        int a, b;
        cin >> a >> b;
        ModInt ans = dp[b] - dp[a - 1];
        cout << ans.get() << endl;
    }
}