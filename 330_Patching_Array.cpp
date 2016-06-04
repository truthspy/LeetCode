/**
 * 还得再看
 * 假设nums中已有的[1~i]个数可以组成[1,sumAll]，则此时应该加入sumAll+1，可以组成[1,2sumAll+1]
 */
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int size = nums.size();
        int i = 0;
        long long maxSum = 0;
        int result = 0;
        while(maxSum < n) {
            if(i >= size || maxSum + 1 < nums[i]){
                result ++;
                maxSum = 1 + maxSum * 2;
            }
            else {
                maxSum += nums[i];
                i ++;
            }
        }
        return result;
    }
};
