class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        unordered_map<int, bool> ht;
        vector<int> result;
        for(int i = 0; i < size1; i ++) {
            ht[nums1[i]] = true;
        }
        for(int i = 0; i < size2; i ++) {
            if(ht.find(nums2[i]) != ht.end()) {
                if(ht[nums2[i]]) {
                    result.push_back(nums2[i]);
                    ht[nums2[i]] = false;
                }
            }
        }
        return result;
    }
};
