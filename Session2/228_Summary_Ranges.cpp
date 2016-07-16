class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int size = nums.size();
        if(size == 0)
            return res;
        int start = nums[0];
        string curRes = "";
        for(int i = 1; i < size; i ++) {
            if(nums[i] == nums[i - 1] + 1)
                continue;
            else {
                curRes = to_string(start);
                if(nums[i - 1] != start)
                    curRes += ("->" + to_string(nums[i - 1]));
                res.push_back(curRes);
                start = nums[i];
            }
        }
        curRes = to_string(start);
        if(nums[size - 1] != start)
            curRes += ("->" + to_string(nums[size - 1]));
        res.push_back(curRes);
        return res;
    }
};
