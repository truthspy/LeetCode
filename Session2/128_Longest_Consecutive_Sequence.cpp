// 还有两个方法
// 1. 只找一个方向，即在num[i]-1不存在的情况下，才找比它大的
// 2. 类似union-find的方法，再看看
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> mp;
        int n = nums.size();
        for(int i = 0; i < n; i ++)
            mp[nums[i]] = true;
        int res = 1;
        for(int i = 0; i < n; i ++) {
            if(mp[nums[i]] == false)
                continue;
            mp[nums[i]] = false;
            int count = 1;
            int up = nums[i] + 1;
            int down = nums[i] - 1;
            while(mp.find(up) != mp.end()) {
                mp[up] = false;
                count ++;
                up ++;
            }
            while(mp.find(down) != mp.end()) {
                mp[down] = false;
                count ++;
                down --;
            }
            res = max(res, count);
        }
        return res;
    }
};
