/* Author - Neel Aryan (@neelaryan2) */
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
typedef complex<ld> pnt;
#define x real()
#define y imag()
constexpr ld eps = 1e-8;
int n;
ld ans = 0;
vector<pnt> vec;
vector<vector<ld>> dist;
void updateCirc(int t, int u, int v) {
    pnt A = vec[t], B = vec[u], C = vec[v];
    ld a = norm(B - C), b = norm(C - A), c = norm(A - B);
    ld aa = a * (b + c - a);
    ld bb = b * (a + c - b);
    ld cc = c * (b + a - c);
    if (aa < eps || bb < eps || cc < eps) return;
    ld s = aa + bb + cc;
    aa /= s, bb /= s, cc /= s;
    pnt D = aa * A + bb * B + cc * C;
    ld ref = abs(D - A);
    for (int j = 0; j < n; j++) {
        if (j == t || j == u || j == v) continue;
        ld d = abs(D - vec[j]) - ref;
        if (d < -eps) return;
    }
    ans = max(ans, ref);
}
void updateSq(int t, int u, int v) {
    pnt A = vec[t], B = vec[u], C = vec[v];
    pnt D = B + C - A;
    for (int i = 0; i < n; i++) {
        if (abs(D - vec[i]) < eps) {
            D = (B + C) * pnt(0.5, 0);
            ld ref = abs(D - A);
            for (int j = 0; j < n; j++) {
                if (j == t || j == i || j == u || j == v) continue;
                ld d = abs(D - vec[j]) - ref;
                if (d < -eps) return;
            }
            ans = max(ans, ref);
            return;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vec.resize(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        vec[i] = pnt(u, v);
    }
    dist.assign(n, vector<ld>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = abs(vec[i] - vec[j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                updateCirc(i, j, k);
                if (abs(dist[i][j] - dist[i][k]) > eps) continue;
                pnt c = (conj(vec[j] - vec[i]) * (vec[k] - vec[i]));
                if (abs(c.x) > eps) continue;
                updateSq(i, j, k);
            }
        }
    }
    if (ans < eps) {
        cout << "-1\n";
        return 0;
    }
    cout << fixed << setprecision(6) << ans << '\n';
}
