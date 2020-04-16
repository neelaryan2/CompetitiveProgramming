#include <bits/stdc++.h>
using namespace std;

const int kMod = 998244353;
struct ModInt {
    long long n;
    ModInt(long long n = 0) : n(n % kMod) {}
    ModInt operator+(const ModInt& oth) { return n + oth.n; }
    ModInt operator-(const ModInt& oth) { return n - oth.n; }
    ModInt operator*(const ModInt& oth) { return n * oth.n; }
    long long get() { return n < 0 ? n + kMod : n; }
};

ModInt dp1[1001][2001], dp2[1001][2001];

int main() {
    int n, k;
    cin >> n >> k;
    for (int j = 0; j < k; j++) {
        dp1[0][j] = 0;
        dp2[0][j] = 0;
    }
    for (int i = 0; i < n; i++) {
        dp1[i][0] = 2;
        dp2[i][0] = 0;
    }
    dp1[0][0] = dp2[0][1] = 2;
    for (int j = 1; j < k; j++) {
        for (int i = 1; i < n; i++) {
            dp1[i][j] = dp1[i - 1][j] + dp1[i - 1][j - 1] + dp2[i - 1][j] * 2;
            dp2[i][j] = dp1[i - 1][j - 1] * 2 + dp2[i - 1][j];
            if (j > 1) dp2[i][j] = dp2[i][j] + dp2[i - 1][j - 2];
        }
    }
    ModInt ans = dp1[n-1][k-1] + dp2[n-1][k-1];
    cout << ans.get() << endl;
}