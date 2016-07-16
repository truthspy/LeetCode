class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> res;
        for(int i = 0; i < len1; i ++) {
            if(mp.find(nums1[i]) == mp.end()) {
                mp[nums1[i]] = 1;
            }
        }
        for(int i = 0; i < len2; i ++) {
            if(mp.find(nums2[i]) != mp.end() && mp[nums2[i]] != 0) {
                mp[nums2[i]] = 0;
                res.push_back(nums2[i]);
            }
        }
        return res;
    }
};
