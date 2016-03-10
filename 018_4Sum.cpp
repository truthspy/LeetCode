class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        // if(size == 0)
        //     return result;
        for(int i = 0; i < size - 3; i ++) {
            if(i != 0 && nums[i] == nums[i - 1])
                continue;
            for(int j = i + 1; j < size - 2; j ++) {
                if(j != (i + 1) && nums[j] == nums[j - 1])
                    continue;
                int curTarget = target - nums[i] - nums[j];
                int m = j + 1;
                int n = size - 1;
                while(m < n) {
                    if(nums[m] + nums[n] == curTarget) {
                        vector<int> solution;
                        solution.push_back(nums[i]);
                        solution.push_back(nums[j]);
                        solution.push_back(nums[m]);
                        solution.push_back(nums[n]);
                        result.push_back(solution);
                        m ++;
                        while(m < n && nums[m] == nums[m - 1])
                            m ++;
                        n --;
                        while(m < n && nums[n] == nums[n + 1])
                            n --;
                    }
                    else if(nums[m] + nums[n] > curTarget) {
                        n --;
                        while(m < n && nums[n] == nums[n + 1])
                            n --;
                    }
                    else {
                        m ++;
                        while(m < n && nums[m] == nums[m - 1])
                            m ++;
                    }
                }
            }
        }
        return result;
    }
};

//TODO
//有更快的方法
