class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n - 3; i ++) {
            for(int j = i + 1; j < n - 2; j ++) {
                int l = j + 1;
                int r = n - 1;
                int cur = nums[i] + nums[j];
                while(l < r) {
                    int sum = cur + nums[l] + nums[r];
                    if(target == sum) {
                        vector<int> curRes;
                        curRes.push_back(nums[i]);
                        curRes.push_back(nums[j]);
                        curRes.push_back(nums[l]);
                        curRes.push_back(nums[r]);
                        res.insert(curRes);
                        l ++;
                        r --;
                    }
                    else if(target > sum)
                        l ++;
                    else
                        r --;
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};
