class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int n = nums.size();
        int pre = lower - 1;
        nums.push_back(upper + 1);
        for(int i = 0; i <= n; i ++) {
            if(nums[i] != (pre + 1)){
                int start = pre + 1;
                int end = nums[i] - 1;
                if(start == end)
                    res.push_back(to_string(start));
                else {
                    res.push_back(to_string(start) + "->" + to_string(end));
                }
            }
            pre = nums[i];
        }
        return res;
    }
};
