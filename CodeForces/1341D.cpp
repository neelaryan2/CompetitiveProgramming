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
const int inf = 1e9;
vector<vi> dist(128, vi(128));
vector<int> num(10);

int calc(int i, int j) {
    int cnt = 0;
    for (int b = 0; b < 7; b++) {
        int b1 = (i >> b) & 1;
        int b2 = (j >> b) & 1;
        if (b1 == b2) continue;
        if (b1 == 1) return -1;
        if (b1 == 0) cnt++;
    }
    return cnt;
}
int getNum(string s) {
    int ans = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        ans = 2 * ans + (s[i] - '0');
    }
    return ans;
}
void precalc() {
    num[0] = getNum("1110111");
    num[1] = getNum("0010010");
    num[2] = getNum("1011101");
    num[3] = getNum("1011011");
    num[4] = getNum("0111010");
    num[5] = getNum("1101011");
    num[6] = getNum("1101111");
    num[7] = getNum("1010010");
    num[8] = getNum("1111111");
    num[9] = getNum("1111011");
    for (int i = 0; i < 128; i++) {
        for (int j = 0; j < 128; j++) {
            dist[i][j] = calc(i, j);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precalc();
    int n, k;
    cin >> n >> k;
    vector<vi> can(n + 1, vi(k + 1, false));
    can[n][0] = true;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int t = getNum(s);
        arr[i] = t;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int l = 0; l < 10; l++) {
            int d = dist[arr[i]][num[l]];
            if (d == -1) continue;
            for (int j = d; j <= k; j++) {
                if (can[i + 1][j - d]) can[i][j] = true;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!can[i][k]) {
            cout << -1 << endl;
            return 0;
        }
        for (int l = 9; l >= 0; l--) {
            int d = dist[arr[i]][num[l]];
            if (k < d || d == -1) continue;
            if (can[i + 1][k - d]) {
                arr[i] = l;
                k -= d;
                break;
            }
        }
    }
    for (int i : arr) cout << i;
    cout << endl;
}