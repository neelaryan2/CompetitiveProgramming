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

bool solve() {
    int n;
    cin >> n;
    vector<int> pos(n), arr(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        pos[a - 1] = i;
        arr[i] = a - 1;
    }
    for (int i = 0; i < pos.size(); i++) {
        int cur = pos[i];
        for (int j = cur + 1; j < n; j++, i++) {
            if (arr[j] - arr[j - 1] != 1)
                return false;
        }
        n = cur;
    }
    return (n == 0);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        puts(solve() ? "Yes" : "No");
}