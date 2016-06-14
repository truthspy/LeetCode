/**
 * 看了答案
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        int size = nums.size();
        while(i < size) {
            if(nums[i] != (i + 1) && nums[i] > 0 && nums[i] <= size && nums[i] != nums[nums[i] - 1]) //注意要最后一个条件，不然会死循环
                swap(nums[i], nums[nums[i] - 1]);
            else
                i ++;       //i++要在else里，不然不正确
        }
        for(i = 0; i < size; i ++) {
            if(nums[i] != i + 1)
                return i + 1;
        }
        return i + 1;
    }
};
/**
 * 以下解法没有注意到空间复杂度要求常熟级别
 */
/*
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, bool> mp;
        int size = nums.size();
        for(int i = 0; i < size; i ++)
            mp[nums[i]] = true;
        for(int i = 1; i <= (size + 1); i ++) {
            if(mp.find(i) == mp.end())
                return i;
        }
        return 1;
    }
};
*/
