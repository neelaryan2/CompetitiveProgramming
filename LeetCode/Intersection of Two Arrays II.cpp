class Solution {
   public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        map<int, int> mp;
        for (int i : nums1) mp[i]++;
        vector<int> ans;
        for (int i : nums2) {
            if (mp.find(i) == mp.end() || mp[i] == 0) continue;
            mp[i]--;
            ans.emplace_back(i);
        }
        return ans;
    }
};