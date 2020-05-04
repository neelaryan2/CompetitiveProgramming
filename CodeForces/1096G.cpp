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
struct NTT {
    int MOD, root, root_1, root_pw;
    int get(ll num) {
        num %= MOD;
        if (num < 0) num += MOD;
        return num;
    }
    int exp(int x, int a) {
        x = get(x), a %= MOD - 1;
        if (x == 0) return 0;
        if (a < 0) a += MOD - 1;
        int res = 1;
        while (a) {
            if (a & 1) res = get(1LL * res * x);
            x = get(1LL * x * x);
            a >>= 1;
        }
        return res;
    }
    NTT(int mod) {
        MOD = mod;
        int r = 2, pw = 0, phi = --mod;
        while (exp(r, mod >> 1) == 1) ++r;
        assert(exp(r, mod) == 1);
        while (!(mod & 1)) mod >>= 1, pw++;
        root = exp(r, phi >> pw);
        root_1 = exp(root, -1);
        root_pw = 1 << pw;
        cerr << "MOD : " << MOD << '\n';
        cerr << "root : " << root << '\n';
        cerr << "root_1 : " << root_1 << '\n';
        cerr << "root_pw : " << root_pw << '\n';
    }
    void fft(vector<int>& a, bool invert) {
        int n = a.size();
        assert((n & (n - 1)) == 0);
        assert(n <= root_pw);
        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for (; j & bit; bit >>= 1)
                j ^= bit;
            j ^= bit;
            if (i < j)
                swap(a[i], a[j]);
        }
        for (int len = 2; len <= n; len <<= 1) {
            int wlen = invert ? root_1 : root;
            for (int i = len; i < root_pw; i <<= 1)
                wlen = get(1LL * wlen * wlen);
            for (int i = 0; i < n; i += len) {
                int w = 1;
                for (int j = 0; j < len / 2; j++) {
                    int u = get(a[i + j]);
                    int v = get(1LL * a[i + j + len / 2] * w);
                    a[i + j] = get(1LL * u + v);
                    a[i + j + len / 2] = get(1LL * u - v);
                    w = get(1LL * w * wlen);
                }
            }
        }
        if (invert) {
            int invN = exp(n, -1);
            for (int i = 0; i < n; i++)
                a[i] = get(1LL * a[i] * invN);
        }
    }
    vector<int> multiply(vector<int> const& a, vector<int> const& b) {
        vector<int> fa = a, fb = b;
        int n = 1, tot = a.size() + b.size();
        while (n < tot) n <<= 1;
        fa.resize(n), fb.resize(n);
        fft(fa, false), fft(fb, false);
        for (int i = 0; i < n; i++)
            fa[i] = fa[i] * fb[i];
        fft(fa, true);
        vector<int> result(tot - 1);
        for (int i = 0; i < tot - 1; i++)
            result[i] = fa[i];
        return result;
    }
};
const int mod = 998244353;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, sz = 1;
    cin >> n >> k;
    while (sz < 5 * n) sz <<= 1;
    vector<int> a(sz, 0);
    for (int i = 0; i < k; i++) {
        int e;
        cin >> e;
        a[e] = 1;
    }
    NTT ntt = NTT(mod);
    ntt.fft(a, false);
    for (int& i : a) i = ntt.exp(i, n / 2);
    ntt.fft(a, true);
    ll ans = 0;
    for (int i : a)
        ans = ntt.get(ans + 1LL * i * i);
    cout << ans << '\n';
}
