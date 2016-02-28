/**
 * O(n)空间复杂度思路：
 * 从前往后，记录在当前节点之前的最小值
 * 从后往前，记录在当前节点之后的最大值
 * 再次遍历，如果之前的最小值小于当前节点，并且之后的最大值大于当前节点，满足
 */

/**
 * O(1)空间复杂度 from discuss
 * 
 */
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int size = nums.size();
        int small = INT_MAX;
        int big = INT_MAX;
        for(int i = 0; i < size; i ++) {
            if(nums[i] <= small)
                small = nums[i];
            else if(nums[i] <= big)
                big = nums[i];
            else
                return true;
        }
        return false;
    }
};
