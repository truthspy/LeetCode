class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int size = nums.size();
        //需要先排序！！！！！
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for(int i = 0; i < size; i ++) {
            mp[nums[i]] = i;
        }
        for(int i = 0; i < size; i ++) {
            if(i != 0 && nums[i] == nums[i - 1])
                continue;
            for(int j = i + 1; j < size; j ++) {
                if(j != (i + 1) && nums[j] == nums[j - 1])
                    continue;
                int toFind = 0 - nums[i] - nums[j];
                if(mp.find(toFind) == mp.end())
                    continue;
                if(mp[toFind] > j) {
                    vector<int> cur;
                    cur.push_back(nums[i]);
                    cur.push_back(nums[j]);
                    cur.push_back(toFind);
                    res.push_back(cur);
                }
            }
        }
        return res;
    }
};
