#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
void solve() {
    string r, s;
    cin >> s >> r;
    while (!s.empty() && s.back() == r.back())
        s.pop_back(), r.pop_back();
    reverse(s.begin(), s.end());
    reverse(r.begin(), r.end());
    while (!s.empty() && s.back() == r.back())
        s.pop_back(), r.pop_back();
    ll l = 0, k = 0;
    vector<int> eq;
    while (!s.empty()) {
        int cnt1 = 0, cnt2 = 0;
        while (!s.empty() && s.back() != r.back()) {
            cnt1++;
            s.pop_back(), r.pop_back();
        }
        while (!s.empty() && s.back() == r.back()) {
            cnt2++;
            s.pop_back(), r.pop_back();
        }
        if (cnt2 != 0) eq.push_back(cnt2);
        l += cnt1;
        k++;
    }
    sort(eq.begin(), eq.end());
    ll sum = 0, num = 0;
    for (int i = 0; i < eq.size(); i++) {
        sum += eq[i];
        num++;
        if (k <= num) break;
        if (sum * (k - num) <= l * num) {
            l += sum;
            k -= num;
            sum = 0;
            num = 0;
        }
    }
    cout << (k * l) << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
}