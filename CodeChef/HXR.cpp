#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 502;
using vi = bitset<N>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define sz(v) int((v).size())
void matmul(vector<vi>& Ar, vector<vi>& Ac, vector<vi>& Br, vector<vi>& Bc) {
    vector<vi> Cr(N), Cc(N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            Cr[i][j] = Cc[j][i] = (Ar[i] & Bc[j]).count() & 1;
        }
    for (int i = 0; i < N; i++) {
        Ar[i] = Cr[i];
        Ac[i] = Cc[i];
    }
}
void matexp(vector<vi>& Ar, vector<vi>& Ac, vector<vi>& ansr, vector<vi>& ansc, int k) {
    for (int i = 0; i < N; i++) ansc[i][i]=ansr[i][i]=1;
    while (k) {
        if (k & 1) matmul(ansr, ansc, Ar, Ac);
        matmul(Ar, Ac, Ar, Ac);
        k >>= 1;
    }
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (ll& e : arr) cin >> e;
    vector<vi> Ar(N), Ac(N), ansc(N), ansr(N);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        for (int j = l; j <= r; j++){
            Ar[i][j] = 1;
            Ac[j][i] = 1;
        }
    }
    matexp(Ar, Ac, ansr, ansc, k - 1);
    for (int i = 0; i < n; i++) {
        ll ans = 0;
        for (int j = 0; j < n; j++) {
            if (ansr[i][j]) {
                ans ^= arr[j];
            }
        }
        cout << ans << ' ';
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}