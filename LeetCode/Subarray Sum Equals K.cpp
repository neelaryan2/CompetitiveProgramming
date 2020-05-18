using ll = long long;
class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<ll, int> cnt;
        ll ans = 0, sum = 0;
        cnt[0]++;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            auto it = cnt.find(sum - k);
            if (it != cnt.end()) ans += it->second;
            cnt[sum]++;
        }
        return ans;
    }
};