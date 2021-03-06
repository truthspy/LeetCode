class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> visited(nums.size(), false);
        getPermutations(0, cur, res, nums, visited);
        return res;
        
    }
    void getPermutations(int pos, vector<int> cur,vector<vector<int>>& res, vector<int>& nums, vector<bool>& visited) {
        if(pos == nums.size()) {
            res.push_back(cur);
            return;
        }
        for(int i = 0; i < nums.size(); i ++) {
            if(!visited[i]) {
                visited[i] = true;
                cur.push_back(nums[i]);
                getPermutations(pos + 1, cur, res, nums, visited);
                visited[i] = false;
                cur.pop_back();
            }
        }
    }
};
