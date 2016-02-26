/**
todo:
分治法做
**/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> endSum;
        int maxSum = INT_MIN;
        int size = nums.size();
        for(int i = 0; i < size; i ++) {
            if(i == 0)
                endSum.push_back(nums[i]);
            else {
                int tmp = endSum[i - 1] + nums[i];
                endSum.push_back(max(nums[i],tmp));
            }
            maxSum = max(maxSum, endSum[i]);
        }
        return maxSum;
    }
};
