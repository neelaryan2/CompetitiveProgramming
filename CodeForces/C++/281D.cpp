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
    vector<int> arr(n);
    for (int& e : arr) cin >> e;
    stack<int> st;
    int ans = -1;
    for (int j : {0, 1}) {
        for (int a : arr) {
            while (!st.empty() && st.top() < a) {
                ans = max(ans, a ^ st.top());
                st.pop();
            }
            st.push(a);
        }
        while (!st.empty()) st.pop();
        reverse(all(arr));
    }
    cout << ans << endl;
}