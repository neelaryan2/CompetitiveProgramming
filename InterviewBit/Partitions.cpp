using ll = long long;
int Solution::solve(int n, vector<int> &a) {
    ll sum = 0;
    for (int& e : a) sum += e;
    if (sum % 3) return 0;
    sum /= 3;
    vector<ll> pref(n), suff(n);
    pref[0] = a[0];
    suff[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++) 
        pref[i] = pref[i - 1] + a[i];
    for (int i = n - 2; i >= 0; i--)
        suff[i] = suff[i + 1] + a[i];
    int ans = 0;
    map<ll, int> cnt;
    for (ll e : suff) cnt[e]++;
    cnt[suff[0]]--;
    for (int i = 0; i < n - 1; i++) {
        cnt[suff[i + 1]]--;
        if (pref[i] == sum)
            ans += cnt[sum];
    }
    return ans;
}
