class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> solution;
        getSubsets(nums, result, solution, 0);
        return result;
    }
    void getSubsets(vector<int>& nums, vector<vector<int>>& result, vector<int> solution, int start) {
        result.push_back(solution);
        int size = nums.size();
        for(int i = start; i < size; i ++){
            if(i != start && nums[i] == nums[i - 1])
                continue;
            solution.push_back(nums[i]);
            getSubsets(nums, result, solution, i + 1);
            solution.pop_back();
        }
    }
};

//discuss里还有一种解法没看
