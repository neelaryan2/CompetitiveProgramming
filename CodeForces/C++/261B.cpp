#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<ld>;
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
    int p;
    cin >> p;
    vector<vi> dp(n + 1, vi(p + 1));
    dp[0][0] = 1;
    for (int& cur : a)
        for (int j = n - 1; j >= 0; j--)
            for (int s = 0; s + cur <= p; s++)
                dp[j + 1][s + cur] += (dp[j][s] / (n - j)) * (j + 1);
            }
        }
    }
    ld ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= p; j++)
            ans += dp[i][j];
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
}