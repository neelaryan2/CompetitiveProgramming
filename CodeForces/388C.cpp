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
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> vec;
    int clei = 0, jiro = 0;
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s;
        int h = s / 2;
        for (int j = 0; j < h; j++) {
            cin >> e;
            clei += e;
        }
        if (s & 1) cin >> e, vec.pb(e), h++;
        for (int j = h; j < s; j++) {
            cin >> e;
            jiro += e;
        }
    }
    sort(rall(vec));
    int f = 1;
    for (int& e : vec) {
        if (f)
            clei += e;
        else
            jiro += e;
        f ^= 1;
    }
    cout << clei << " " << jiro << '\n';
}
