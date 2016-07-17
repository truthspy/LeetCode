class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> res;
        unordered_map<int, int> mp;
        for(int i = 0; i < size1; i ++) {
            if(mp.find(nums1[i]) == mp.end())
                mp[nums1[i]] = 1;
            else
                mp[nums1[i]] ++;
        }
        for(int i = 0; i < size2; i ++) {
            if(mp.find(nums2[i]) != mp.end() && mp[nums2[i]] > 0) {
                mp[nums2[i]] --;
                res.push_back(nums2[i]);
            }
        }
        return res;
    }
};
