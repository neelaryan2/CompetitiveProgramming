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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> vec(256, -1), arr(n);
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        arr[i] = e;
        if (vec[e] != -1) continue;
        int l = max(e - k + 1, 0);
        while (vec[l] != -1 && vec[l] != l) l++;
        for (int j = e; j >= l && vec[j] == -1; j--)
            vec[j] = l;
    }
    trace(vec);
    for (int i : arr) cout << vec[i] << " ";
    cout << '\n';
}
