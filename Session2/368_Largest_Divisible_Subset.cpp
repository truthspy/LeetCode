// 如果a < b < c，且a,b,c在同一个满足条件的subset里，那么必然有b % a == 0 && c % b == 0 && c % a ==0
// 也即，如果c % b == 0, 并且a和b已经在同一个subset里，则c % a == 0
// 也就是说，如果先对数组排序，可以采用类似最大上升子序列的方法来实现
// 因为要返回结果数组，所以需要用parent记录一下顺序
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);
        vector<int> res;
        sort(nums.begin(), nums.end());
        int maxLen = 0;
        int endIndex = -1;
        for(int i = 0; i < n; i ++) {
            for(int j = i - 1; j >= 0; j --) {
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if(dp[i] > maxLen) {
                maxLen = dp[i];
                endIndex = i;
            }
        }
        while(endIndex != -1) {
            res.push_back(nums[endIndex]);
            endIndex = parent[endIndex];
        }
        return res;
    }
};
