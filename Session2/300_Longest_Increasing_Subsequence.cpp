// O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        int n = nums.size();
        if(n == 0)
            return 0;
        dp.push_back(nums[0]);
        for(int i = 1; i < n; i ++) {
            if(nums[i] < dp[0])
                dp[0] = nums[i];
            else if(nums[i] > dp[dp.size() - 1])
                dp.push_back(nums[i]);
            else {
                int l = 0;
                int r = dp.size() - 1;
                while(l <= r) {
                    int mid = (l + r) / 2;
                    cout << mid << endl;
                    if(nums[i] > dp[mid])
                        l = mid + 1;
                    else
                        r = mid - 1;
                }
                dp[l] = nums[i];
            }
        }
        return dp.size();
    }
};
/*
O(n^2) DP
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        vector<int> dp(n, 1);
        int res = 1;
        for(int i = 1; i < n; i ++) {
            for(int j = i - 1; j >= 0; j --) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
*/
