#include <bits/stdc++.h>
using namespace std;

string get(queue<int>& q) {
    string ans;
    queue<int> cpy = q;
    while (!cpy.empty()) {
        int c = cpy.front();
        cpy.pop();
        ans += (char)(c + '0');
    }
    return ans;
}
map<string, bool> vis1, vis2;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k1, k2;
    queue<int> q1, q2;
    cin >> n;
    cin >> k1;
    for (int i = 0; i < k1; i++) {
        int a;
        cin >> a;
        q1.push(--a);
    }
    cin >> k2;
    for (int i = 0; i < k2; i++) {
        int a;
        cin >> a;
        q2.push(--a);
    }
    vis1[get(q1)] = true;
    vis2[get(q2)] = true;
    int cnt = 0;
    while (!q1.empty() && !q2.empty()) {
        int c1 = q1.front(), c2 = q2.front();
        q1.pop(), q2.pop();
        if (c1 > c2) {
            q1.push(c2);
            q1.push(c1);
        } else {
            q2.push(c1);
            q2.push(c2);
        }
        string s1 = get(q1), s2 = get(q2);
        if (vis1[s1] && vis2[s2]) {
            cout << -1 << endl;
            return 0;
        } else {
            vis1[s1] = true;
            vis2[s2] = true;
        }
        cnt++;
    }
    cout << cnt << " ";
    if (q1.empty())
        cout << 2 << endl;
    else
        cout << 1 << endl;
}