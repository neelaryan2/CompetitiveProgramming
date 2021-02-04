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
const int N = 1e6 + 5;
int cnt[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, mn = N;
    cin >> n >> k;
    memset(cnt, 0, 4 * N);
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        mn = min(mn, e);
        cnt[e]++;
    }
    for (int i = 1; i < N; i++)
        cnt[i] += cnt[i - 1];
    int ans = min(k + 1, mn);
    for (int i = mn; i > k + 1; i--) {
        int amt = 0;
        for (int j = i; j < N; j += i) {
            int r = min(j + k, N - 1);
            amt += cnt[r] - cnt[j - 1];
        }
        if (amt == n) {
            ans = i;
            break;
        }
    }
    cout << ans << '\n';
}
