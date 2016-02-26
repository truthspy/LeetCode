class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> myresult;
        for(int i = 0; i < size; i ++) {
            vector<int> result;
            result.push_back(nums[i]);
            vector<bool> flag(size, false);
            flag[i] = true;
            findNext(nums, flag, result, myresult);
        }
        return myresult;
    }
    void findNext(vector<int>& nums, vector<bool> flag, vector<int> result, vector<vector<int>>& myresult) {
        int size = nums.size();
        bool tmp = false;
        for(int i = 0; i < size; i ++) {
            if(flag[i] == false) {
                flag[i] = true;
                tmp = true;
                result.push_back(nums[i]);
                findNext(nums, flag, result, myresult);
                //记着回溯！！！！！！！！
                flag[i] = false;
                result.erase(result.end()-1);
            }
        }
        if(!tmp)
            myresult.push_back(result);
        
    }
};
