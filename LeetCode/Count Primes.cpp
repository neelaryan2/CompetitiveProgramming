class Solution {
   public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> is(n, true);
        is[0] = is[1] = false;
        for (int i = 2; i * i < n; i++) {
            if (!is[i]) continue;
            for (int j = i * i; j < n; j += i)
                is[j] = false;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (is[i]) cnt++;
        return cnt;
    }
};