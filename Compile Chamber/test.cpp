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
#include "trace.h"



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<pair<pii,int>> vec(100,{{2,3},1});
    // trace(vec);
    // debug()<<imie(vec);
    queue<int> q;
    q.push(1);
    q.push(1);
    // trace(q);
    debug()<<imie(q);
}
