class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        result.push_back(nums);
        vector<int> curPermutation = nums;
        while(true) {
            int pos = haveNextPermutation(curPermutation);
            if(pos == 0)
                break;
            nextPermutation(curPermutation, pos);
            result.push_back(curPermutation);
        }
        return result;
    }
    void nextPermutation(vector<int>& curPermutation, int pos) {
        int curPos = pos - 1;
        int curVal = curPermutation[curPos];
        while(pos < curPermutation.size()) {
            if(curPermutation[pos] <= curVal) //要记得等于号！！！
                break;
            pos ++;
        }
        pos --;
        swap(curPermutation[curPos], curPermutation[pos]);
        reverse(curPermutation.begin() + curPos + 1, curPermutation.end());
    }
    int haveNextPermutation(vector<int> curPermutation) {
        int i = curPermutation.size() - 1;
        while(i > 0) {
            if(curPermutation[i - 1] < curPermutation[i])
                return i;
            i --;
        }
        return 0;
    }
};
