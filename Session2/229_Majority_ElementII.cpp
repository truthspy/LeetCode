class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int major1 = 0;
        int major2 = 0;
        int count1 = 0;
        int count2 = 0;
        for(int i = 0; i < nums.size(); i ++) {
            // the order of if and else are really important!!!
            // cannot judge count==0 first
            if(major1 == nums[i])
                count1 ++;
            else if(major2 == nums[i])
                count2 ++;
            else if(count1 == 0) {
                count1 ++;
                major1 = nums[i];
            }else if(count2 == 0) {
                count2 ++;
                major2 = nums[i];
            }
            else {
                count1 --;
                count2 --;
            }
        }
        count1 = 0;
        count2 = 0;
        for(int i = 0; i < nums.size(); i ++) {
            if(nums[i] == major1)
                count1 ++;
            else if(nums[i] == major2)
                count2 ++;
        }
        vector<int> res;
        if(count1 > (nums.size() / 3))
            res.push_back(major1);
        if(count2 > (nums.size() / 3))
            res.push_back(major2);
        return res;
    }
};
