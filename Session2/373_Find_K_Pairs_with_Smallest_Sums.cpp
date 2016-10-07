class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> res;
        if(k == 0)
            return res;
        int size1 = nums1.size();
        int size2 = nums2.size();
        if(size1 == 0 || size2 == 0)
            return res;
        k = min(k, size1 * size2);
        vector<int> index(size1, 0);
        while(k > 0) {
            k --;
            int curMax = INT_MAX;
            int maxPos = 0;
            for(int i = 0; i < size1; i ++) {
                if(index[i] < size2 && (curMax > (nums1[i] + nums2[index[i]]))) {
                    curMax = nums1[i] + nums2[index[i]];
                    maxPos = i;
                }
            }
            res.push_back(make_pair(nums1[maxPos], nums2[index[maxPos]]));
            index[maxPos] ++;
        }
        return res;
    }
};
