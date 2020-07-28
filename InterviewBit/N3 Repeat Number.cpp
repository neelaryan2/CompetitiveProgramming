int Solution::repeatedNumber(const vector<int> &A) {
    const int k = 3;
    int n = A.size();
    vector<int> cnt(k, 0), candidate(k, -1);
    for (int i = 0; i < n; i++) {
        bool updated = false;
        for (int j = 0; j < k; j++) {
            if (candidate[j] == A[i]) {
                cnt[j]++, updated = true;
                break;
            }
        }
        if (updated) continue;
        for (int j = 0; j < k; j++) {
            if (cnt[j] == 0) {
                cnt[j]++, updated = true;
                candidate[j] = A[i];
                break;
            }
        }
        if (updated) continue;
        for (int j = 0; j < k; j++)
            cnt[j]--;
    }
    cnt.assign(k, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (candidate[j] == A[i]) {
                cnt[j]++;
                break;
            }
        }
    }
    for (int j = 0; j < k; j++)
        if (cnt[j] > n / k) 
            return candidate[j];
    return -1;
}