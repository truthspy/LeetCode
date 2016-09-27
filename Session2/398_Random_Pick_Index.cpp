class Solution {
private:
    vector<int> v;
public:
    Solution(vector<int> nums) {
        v = nums;
    }
    
    int pick(int target) {
        int count = 0;
        int res = 0;
        for(int i = 0; i < v.size(); i ++) {
            if(v[i] != target)
                continue;
            count ++;
            // reservoir-sampling! The possiblity of cur is choosen is 1/n
            if(rand() % count == 0)
                res = i;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */

// Below method is Memory Exceeded 
/*
class Solution {
private:
    unordered_map<int, vector<int>> mp;
public:
    Solution(vector<int> nums) {
        for(int i = 0; i < nums.size(); i ++) {
            mp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int size = mp[target].size();
        int pos = rand() % size;
        return mp[target][pos];
    }
};
*/
