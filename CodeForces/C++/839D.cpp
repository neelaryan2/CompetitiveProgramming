#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
int N = 1e6 + 10;

const int kMod = 1e9 + 7;
struct ModInt {
    long long n;
    ModInt(long long n = 0) : n(n % kMod) {}
    ModInt operator+(const ModInt& oth) { return n + oth.n; }
    ModInt operator-(const ModInt& oth) { return n - oth.n; }
    ModInt operator*(const ModInt& oth) { return n * oth.n; }
    long long get() { return n < 0 ? n + kMod : n; }
};
ModInt lgpow(ModInt b, int e = -1) {
    if (b.get() == 0) return 0;
    ModInt r;
    e = e % (kMod - 1);
    if (e < 0) e += kMod - 1;
    for (r = 1; e; e >>= 1, b = b * b)
        if (e & 1) r = r * b;
    return r;
}
vector<int> cnt(N, 0);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, mx = -1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        cnt[e]++;
        mx = max(mx, e);
    }
    N = mx + 10;
    for (int i = 1; i < N; i++) {
        for (int j = 2 * i; j < N; j += i) {
            if (cnt[j] == 0) continue;
            cnt[i] += cnt[j];
        }
    }
    vector<ModInt> dp(N);
    vector<ModInt> pw(n + 10, 1);
    for (int i = 1; i < pw.size(); i++) {
        pw[i] = pw[i - 1] * 2;
    }
    for (int i = 0; i < N; i++) {
        dp[i] = pw[cnt[i] - 1] * cnt[i];
    }
    for (int i = N - 1; i > 1; i--) {
        if (cnt[i] == 0) continue;
        for (int j = 2 * i; j < N; j += i) {
            if (cnt[j] == 0) continue;
            dp[i] = dp[i] - dp[j];
        }
    }
    ModInt ans = 0;
    for (int i = 2; i < N; i++) {
        ans = ans + dp[i] * i;
    }
    cout << ans.get() << '\n';
}
