class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int lastMax = nums[0];
        int lastMin = nums[0];
        int res = max(lastMax, lastMin);
        for(int i = 1; i < n; i ++) {
            int curMax = max(lastMax * nums[i], lastMin * nums[i]);
            curMax = max(nums[i], curMax);
            int curMin = min(lastMin * nums[i], lastMax * nums[i]);
            curMin = min(nums[i], curMin);
            res = max(curMax, res);
            lastMax = curMax;
            lastMin = curMin;
        }
        return res;
    }
};
