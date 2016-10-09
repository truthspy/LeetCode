class NumArray {
private:
    vector<int> dp;
public:
    NumArray(vector<int> &nums) {
        int n = nums.size();
        dp.resize(n);
        if(n == 0)
            return;
        dp[0] = nums[0];
        for(int i = 1; i < n; i ++)
            dp[i] = dp[i - 1] + nums[i];
    }

    int sumRange(int i, int j) {
        if(i == 0)
            return dp[j];
        return dp[j] - dp[i - 1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
