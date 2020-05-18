class Solution {
   public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int k = 0, n = s.size();
        for (auto v : shift) {
            k += ((2 * v[0] - 1) * v[1]) % n;
            k = (k % n + n) % n;
        }
        reverse(s.begin(), s.begin() + n - k);
        reverse(s.begin() + n - k, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};