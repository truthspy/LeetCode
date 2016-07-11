class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        vector<int> solution;
        findSolution(candidates, result, solution, target, 0);
        return result;
    }
    void findSolution(vector<int>& candidates, vector<vector<int>>& result, vector<int> solution, int target, int start) {
        if(start >= candidates.size())
            return;
        if(target == 0) {
            result.push_back(solution);
            return;
        }
        if(candidates[start] > target)
            return;
        for(int i = start; i < candidates.size(); i ++) {
            solution.push_back(candidates[i]);
            findSolution(candidates, result, solution, target - candidates[i], i);
            solution.pop_back();
        }
    }
};
