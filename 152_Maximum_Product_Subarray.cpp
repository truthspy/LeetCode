/**
 * 因为有负数的情况，所以还要维护一个局部最小值
 * 以第i个元素结尾的最大值 = max(i-1的最大值*i, i-1的最小值*i, i)
 * 以第i个元素结尾的最小值 = min(i-1的最大值*i, i-1的最小值*i, i)
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        vector<int> local_max(size);
        vector<int> local_min(size);
        local_max[0] = nums[0];
        local_min[0] = nums[0];
        int maxResult = nums[0];
        for(int i = 1; i < size; i ++) {
            local_max[i] = max(max(local_max[i - 1] * nums[i], local_min[i - 1] * nums[i]), nums[i]);
            local_min[i] = min(min(local_max[i - 1] * nums[i], local_min[i - 1] * nums[i]), nums[i]);
            maxResult = max(maxResult, local_max[i]);
        }
        return maxResult;
    }
};
