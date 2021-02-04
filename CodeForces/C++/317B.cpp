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
const int N = 160;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, t;
    cin >> n >> t;
    int cnt[N][N];
    memset(cnt, 0, sizeof(cnt));
    cnt[N / 2][N / 2] = n;
    bool found = true;
    while (found) {
        found = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (cnt[i][j] >= 4) {
                    found = true;
                    int c = cnt[i][j] / 4;
                    cnt[i - 1][j] += c;
                    cnt[i][j - 1] += c;
                    cnt[i + 1][j] += c;
                    cnt[i][j + 1] += c;
                    cnt[i][j] %= 4;
                }
            }
        }
    }
    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        x += N / 2, y += N / 2;
        if (x < 0 || y < 0 || x >= N || y >= N) {
            cout << 0 << '\n';
        } else {
            cout << cnt[x][y] << '\n';
        }
    }
}