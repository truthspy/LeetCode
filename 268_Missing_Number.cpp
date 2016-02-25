//version1 可能溢出
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        int i=0;

        for(int num:nums){
            result ^= num;
            result ^= i;
            i++;
        }

        return result;
    }
};

//version2
/*
相当于一个数组中，除一个数字出现一次，其余全部出现两次
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for(int i = 0; i < n; i ++) {
            result = result ^ i;
            result = result ^ nums[i];
        }
        result = result ^ n;
        return result;
    }
};
