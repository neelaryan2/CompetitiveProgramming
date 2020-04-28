#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define fi first
#define se second
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
const int inf = 1e9 + 7;
set<pii> cnts, nums;
vector<int> arr;
void add(int pos) {
    int a = arr[pos];
    auto it1 = nums.lb(mp(a, -1));
    if (it1 == nums.end() || it1->fi != a) {
        nums.insert(mp(a, 1));
        cnts.insert(mp(1, a));
        return;
    }
    int c = it1->se;
    nums.erase(it1);
    cnts.erase(mp(c, a));
    nums.insert(mp(a, c + 1));
    cnts.insert(mp(c + 1, a));
}
void del(int pos) {
    int a = arr[pos];
    auto it1 = nums.lb(mp(a, -1));
    if (it1 == nums.end() || it1->fi != a) return;
    int c = it1->se;
    nums.erase(it1);
    cnts.erase(mp(c, a));
    if (c == 1) return;
    nums.insert(mp(a, c - 1));
    cnts.insert(mp(c - 1, a));
}
int get() {
    auto it = cnts.lb(mp(2, -inf));
    if (cnts.empty() || it == cnts.begin())
        return inf;
    return (--it)->se;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    arr.resize(n);
    for (int& e : arr) cin >> e;
    for (int i = 0; i < k; i++)
        add(i);
    for (int i = k; i <= n; i++) {
        int ans = get();
        if (ans == inf)
            cout << "Nothing\n";
        else
            cout << ans << '\n';
        if (i == n) break;
        del(i - k), add(i);
    }
}