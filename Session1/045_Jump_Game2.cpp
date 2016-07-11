/**
 * 看了答案哟
 * Method1：http://www.cnblogs.com/lichen782/p/leetcode_Jump_Game_II.html
 * Method2：没看明白这个的代码TODO
 * I try to change this problem to a BFS problem, where nodes in level i are all the nodes that can be reached in i-1th jump. for example. 2 3 1 1 4 , is 2|| 3 1|| 1 4 ||
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int pre = 0;
        int cur = 0;
        int size = nums.size();
        for(int i = 0; i < size; i ++) {
            if(i > pre) {
                pre = cur;
                ans ++;
            }
            cur = max(cur, nums[i] + i);
        }
        return ans;
    }
};
