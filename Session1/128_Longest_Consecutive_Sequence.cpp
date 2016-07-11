/**
 * Method1：看了解答
 * TODO Method2 Union Find
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int size = nums.size();
        for(int i = 0; i < size; i ++) {
            mp[nums[i]] = i;
        }
        int res = 1;
        while(!mp.empty()) {
            int cur = mp.begin()->first;
            int increase = cur + 1;
            int decrease = cur - 1;         //递增递减都要考虑！
            int count = 1;
            while(mp.find(increase) != mp.end()) {
                count ++;
                mp.erase(increase);
                increase ++;
            }
            while(mp.find(decrease) != mp.end()) {
                count ++;
                mp.erase(decrease);
                decrease --;
            }
            res = max(res, count);
            mp.erase(cur);
        }
        return res;
    }
};
