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
const int B = 16;

vector<int> v = {1, 0, 2, 3};

int ask(string typ, int i, int j) {
    if (typ == "XOR") return v[i] ^ v[j];
    if (typ == "AND") return v[i] & v[j];
    if (typ == "OR") return v[i] | v[j];
    return -1;
}

int query(string typ, int i, int j) {
    cout << typ << ' ' << (i + 1);
    cout << ' ' << (j + 1) << endl;
    int ret;
    // ret = ask(typ, i, j);
    cin >> ret;
    if (ret == -1)
        exit(0);
    return ret;
}

vector<int> a;

void solve(int test) {
    int n;
    // n = v.size();
    cin >> n;
    a.assign(n, -1);
    vector<int> xors(n, 0);
    for (int i = 1; i < n; i++)
        xors[i] = query("XOR", 0, i);

    map<int, int> mem;
    int idx = -1;
    for (int i = 0; i < n; i++) {
        if (xors[i] == n - 1) idx = i;
        if (mem.find(xors[i]) != mem.end()) {
            int andij = query("AND", mem[xors[i]], i);
            a[0] = xors[i] ^ andij;
            for (int j = 1; j < n; j++)
                a[j] = a[0] ^ xors[j];
            return;
        } else {
            mem[xors[i]] = i;
        }
    }
    int j = 1 + (idx == 1);
    int and12 = query("AND", 0, j);
    int and23 = query("AND", j, idx);
    int xor23 = xors[j] ^ xors[idx];
    int sum12 = xors[j] + 2 * and12;
    int sum23 = xor23 + 2 * and23;
    int sum13 = n - 1;
    a[0] = (sum12 + sum13 - sum23) / 2;
    for (int i = 1; i < n; i++)
        a[i] = xors[i] ^ a[0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << '!';
        for (int e : a)
            cout << ' ' << e;
        cout << '\n';
    }
}
