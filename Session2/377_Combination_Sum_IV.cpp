// DP比较简单
// 也可以先排序，就可以进行剪枝
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        sort(nums.begin(), nums.end());
        dp[0] = 1;
        for(int i = 1; i <= target; i ++) {
            for(int j = 0; j < nums.size(); j ++) {
                if(nums[j] > i)
                    break;
                dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};

//DFS+记录
/*
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int res = dfs(nums, target, mp);
        return res;
    }
    int dfs(vector<int>& nums, int val, unordered_map<int, int>& mp) {
        if(val == 0) {
            return 1;
        }
        if(mp.find(val) != mp.end())
            return mp[val];
        int res = 0;
        for(int i = 0; i < nums.size(); i ++) {
            if(nums[i] <= val)
                res += dfs(nums, val - nums[i], mp);
        }
        mp[val] = res;
        return res;
    }
};*/
