#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

const int inf = 1e9 + 7;

vector<int> a;
vector<pii> ans;

bool check(int bad) {
    ans.clear();
    ans.eb(a[bad], a.back());
    if (a.size() == 2)
        return true;
    int n = a.size() - 2;
    multiset<int> v;
    for (int i = 0; i < n + 1; i++)
        if (i != bad) v.insert(a[i]);
    int sum = a.back();
    while (!v.empty()) {
        auto it1 = prev(v.end());
        auto it2 = v.lb(sum - *it1);
        if (it2 == v.end() || *it2 + *it1 != sum || it1 == it2)
            return false;
        sum = *it1;
        ans.eb(*it1, *it2);
        v.erase(it1);
        v.erase(it2);
    }
    return true;
}
void solve(int test) {
    int n;
    cin >> n;
    a.resize(2 * n);
    for (int& e : a) cin >> e;
    sort(all(a));
    for (int i = 0; i < 2 * n - 1; i++) {
        if (check(i)) {
            cout << "YES\n";
            cout << (a.back() + a[i]) << '\n';
            for (pii p : ans)
                cout << p.fi << ' ' << p.se << '\n';
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
    }
}
