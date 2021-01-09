using ll = long long;
int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int n = A.size(), ans = -1;
    vector<ll> a(4 * n);
    for (int i = 0; i < n; i++) {
        a[2 * i] = a[2 * (i + n)] = A[i];
        a[2 * i + 1] = a[2 * (i + n) + 1] = -B[i];
    }
    for (int i = 1; i < 4 * n; i++)
        a[i] += a[i - 1];
    deque<int> q;
    for (int i = 0; i < 2 * n; i++) {
        while(!q.empty() && a[q.back()] >= a[i])
            q.pop_back();
        q.push_back(i);
    }
    ll prv = 0;
    for (int i = 2 * n; i < 4 * n; i++) {
        if (a[q.front()] >= prv && (i % 2 == 0)) {
            ans = (i / 2) - n;
            break;
        }
        while(!q.empty() && a[q.back()] >= a[i])
            q.pop_back();
        q.push_back(i);
        prv = a[i - 2 * n];
    }
    return ans;
}
