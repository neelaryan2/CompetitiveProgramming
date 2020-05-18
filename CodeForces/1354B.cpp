/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
int findSubString(string str) {
    int n = str.length();
    int dist_count = 0;
    bool visited[3] = {false};
    for (int i = 0; i < n; i++) {
        if (visited[str[i] - '1'] == false) {
            visited[str[i] - '1'] = true;
            dist_count++;
        }
    }
    for (int i = 0; i < 3; i++)
        if (!visited[i]) return 0;
    int start = 0, start_index = -1, min_len = INT_MAX;
    int count = 0;
    int curr_count[3] = {0};
    for (int j = 0; j < n; j++) {
        curr_count[str[j] - '1']++;
        if (curr_count[str[j] - '1'] == 1)
            count++;
        if (count == dist_count) {
            while (curr_count[str[start] - '1'] > 1) {
                if (curr_count[str[start] - '1'] > 1)
                    curr_count[str[start] - '1']--;
                start++;
            }
            int len_window = j - start + 1;
            if (min_len > len_window) {
                min_len = len_window;
                start_index = start;
            }
        }
    }
    return min_len;
}
void solve() {
    string s;
    cin >> s;
    cout << findSubString(s) << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
