class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int size1 = nums1.size();
        int size2 = nums2.size();
        unordered_map<int, int> ht;
        for(int i = 0; i < size1; i ++) {
            if(ht.find(nums1[i]) == ht.end())
                ht[nums1[i]] = 1;
            else
                ht[nums1[i]] ++;
        }
        for(int i = 0; i < size2; i ++) {
            if(ht.find(nums2[i]) != ht.end()) {
                if(ht[nums2[i]] > 0) {
                    ht[nums2[i]] --;
                    result.push_back(nums2[i]);
                }
            }
        }
        return result;
    }
};
