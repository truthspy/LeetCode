class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        if(nums.size() == 0)
            return result;
        int x1 = 0;
        int x2 = 0;
        int count1 = 0;
        int count2 = 0;
        for(int i = 0; i < nums.size(); i ++) {
            if(nums[i] == x1)
                count1 ++;
            else if(nums[i] == x2)
                count2 ++;
            else if(count1 == 0) {
                count1 ++;
                x1 = nums[i];
            }
            else if(count2 == 0) {
                count2 ++;
                x2 = nums[i];
            }
            else {
                count1 --;
                count2 --;
            }
        }
        count1 = 0;
        count2 = 0;
        for(int i = 0; i < nums.size(); i ++) {
            if(nums[i] == x1)
                count1 ++;
            else if(nums[i] == x2) //必须用else if，否则对于全0的数据，由于初始化为0，会出错
                count2 ++;
        }
        if(count1 > (nums.size() / 3))
            result.push_back(x1);
        if(count2 > (nums.size() / 3))
            result.push_back(x2);
        return result;
    }
};
