class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int len = nums.size();
        if(len == 0)
            return result;
        int start = nums[0];
        int end = nums[0];
        for(int i = 1; i < len; i ++) {
            if(nums[i] != nums[i - 1] + 1) {
                end = nums[i - 1];
                if(start == end) {
                    string tmp = to_string(start);
                    result.push_back(tmp);
                }
                else {
                    string tmp = to_string(start) + "->" + to_string(end);
                    result.push_back(tmp);
                }
                start = nums[i];
            }
        }
        end = nums[len - 1];
        if(start == end) {
            string tmp = to_string(start);
            result.push_back(tmp);
        }
        else {
            string tmp = to_string(start) + "->" + to_string(end);
            result.push_back(tmp);
        }
        return result;
    }
};
