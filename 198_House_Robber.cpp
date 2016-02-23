class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        //注意边界条件！！！！！！！
        if(size == 0)
            return 0;
        if(size == 1)
            return nums[0];
        int *dp = new int[size];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < size; i ++) {
            int tmp1 = dp[i - 2] + nums[i];
            int tmp2 = dp[i - 1];
            dp[i] = max(tmp1, tmp2);
        }
        int max = -1;
        for(int i = 0; i < size; i ++) {
            if(dp[i] > max)
                max = dp[i];
        }
        return max;
    }
};
