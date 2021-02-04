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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    long double ans = 0;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int e = a[i];
        auto it = cnt.find(e - 1);
        if (it != cnt.end())
            ans -= it->se;
        it = cnt.find(e + 1);
        if (it != cnt.end())
            ans += it->se;
        cnt[e]++;
    }
    for (int i = 0; i < n; i++) {
        ans += 1LL * (2 * i + 1 - n) * a[i];
    }
    cout << fixed << setprecision(0) << ans << endl;
}
