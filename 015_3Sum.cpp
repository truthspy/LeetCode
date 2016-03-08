class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> hash;
        for(int i = 0; i < size; i ++) {
            hash[nums[i]] = i;
        }
        for(int i = 0; i < size - 1; i ++) {
            //判重减少重复计算与重复结果
            if(i != 0 && nums[i] == nums[i - 1])
                continue;
            for(int j = i + 1; j < size; j ++) {
                 //判重减少重复计算与重复结果
                if(j != (i + 1) && nums[j] == nums[j - 1])
                    continue;
                int target = 0 - nums[i] - nums[j];
                if(hash.find(target) != hash.end() && hash[target] > j) {
                    vector<int> solution;
                    solution.push_back(nums[i]);
                    solution.push_back(nums[j]);
                    solution.push_back(target);
                    result.push_back(solution);
                }
            }
        }
        return result;
    }
};

//也可以排序之后进行左右夹逼
//要注意对重复数字的判断
