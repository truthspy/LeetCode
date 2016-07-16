class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        unordered_map<int, int> mp;
        vector<int> res;
        for(int i = 0; i < size; i ++) {
            int toFind = target - nums[i];
            if(mp.find(toFind) != mp.end()) {
                res.push_back(mp[toFind]);
                res.push_back(i);
                return res;
            }
            mp[nums[i]] = i;
        }
        return res;
    }
};
