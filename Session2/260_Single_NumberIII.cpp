class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i ++)
            res = res ^ nums[i];
        int pos = 1;
        while(true) {
            if((res & pos) != 0)
                break;
            pos = pos << 1;
        }
        vector<int> myRes(2, 0);
        for(int i = 0; i < nums.size(); i ++) {
            if((nums[i] & pos) == 0)
                myRes[0] = myRes[0] ^ nums[i];
            else
                myRes[1] = myRes[1] ^ nums[i];
        }
        return myRes;
    }
};
