// 此方法行不通，因为要返回下标，排序之后会乱
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> result;
        int i = 0;
        int j = nums.size() - 1;
        while(i < j) {
            int tmp = nums[i] + nums[j];
            if(tmp == target) {
                result.push_back(i);
                result.push_back(j);
                break;
            }
            else if(tmp > target)
                j --;
            else
                i ++;
        }
        return result;
    }
};

//用哈希表查找
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i ++) {
            m[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i ++) {
            if(m.find(target - nums[i]) != m.end()) {
                if(m[target - nums[i]] == i)
                    continue;
                result.push_back(i);
                result.push_back(m[target - nums[i]]);
                break;
            }
        }
        return result;
    }
};
