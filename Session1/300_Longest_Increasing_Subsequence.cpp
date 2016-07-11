//O(n^2)的算法
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return 0;
        int maxLIS = 1;
        vector<int> maxLen(size, 1);
        for(int i = 1; i < size; i ++) {
            for(int j = 0; j < i; j ++) {
                if(nums[i] > nums[j])
                    maxLen[i] = max(maxLen[i], maxLen[j] + 1);
            }
            maxLIS = max(maxLIS, maxLen[i]); 
        }
        return maxLIS;
    }
};

//Todo:
//O(nlogn)的算法
