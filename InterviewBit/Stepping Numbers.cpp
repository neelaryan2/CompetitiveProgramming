#define pb push_back
vector<int> Solution::stepnum(int A, int B) {
    queue<int> q;
    vector<int> ans;
    if (A == 0) ans.pb(0);
    for (int i = 1; i <= 9; i++) {
        if (A <= i && i <= B) ans.pb(i);
        if (i <= B) q.push(i);
    }
    while (!q.empty()) {
        int v = q.front(); q.pop();
        int l = v % 10;
        if (l > 0) {
            int u = v * 10 + l - 1;
            if (A <= u && u <= B) ans.pb(u);
            if (u <= B) q.push(u);
        }
        if (l < 9) {
            int u = v * 10 + l + 1;
            if (A <= u && u <= B) ans.pb(u);
            if (u <= B) q.push(u);
        }
    }
    return ans;
}
