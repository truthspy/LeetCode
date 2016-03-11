class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> solution;
        findSolution(candidates, result, solution, target, 0);
        return result;
    }
    void findSolution(vector<int>& candidates, vector<vector<int>>& result, vector<int> solution, int target, int start) {
        if(target == 0) {
            result.push_back(solution);
            return;
        }
        if(start >= candidates.size() || candidates[start] > target)
            return;
        for(int i = start; i < candidates.size(); i ++) {
            if(i != start && candidates[i] == candidates[i - 1]) //可能有重复数字，要记得判重
                continue;
            solution.push_back(candidates[i]);
            findSolution(candidates, result, solution, target - candidates[i], i + 1);
            solution.pop_back();
        }
    }
};
