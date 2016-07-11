/**
 * 如果抢了第一家，就不能抢最后一家，因为首尾相连了，所以第一家和最后一家只能抢其中的一家，或者都不抢，那我们这里变通一下，如
 * 果我们把第一家和最后一家分别去掉，各算一遍能抢的最大值，然后比较两个值取其中较大的一个即为所求
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) 
            return 0;
        if(size == 1)
            return nums[0];
        vector<int> dp1(size, 0);
        vector<int> dp2(size, 0);
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        dp2[1] = nums[1];
        int amount = dp1[1];
        for(int i = 2; i < size; i ++) {
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
        }
        return max(dp1[size - 2], dp2[size - 1]);
    }
};
