/**
 * 回溯方法
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> solution;
        getSubsets(nums, result, solution, 0);
        return result;
    }
    void getSubsets(vector<int>& nums, vector<vector<int>>& result, vector<int> solution, int start) {
        result.push_back(solution);
        int size = nums.size();
        if(start >= size) {
            return;
        }
        for(int i = start; i < size; i ++) {
            solution.push_back(nums[i]);
            getSubsets(nums, result, solution, i + 1);
            solution.pop_back();
        }
    }
};


//TODO
/**
 * 还可以用位操作
 * 结果一共有2^n种
 * 0-2^n中的每个数用二进制看，可以表示一种subset情况，1表示该位的元素在集合中，0表示不在
 */
