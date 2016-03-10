/**
 * from discuss
 * 从头往后遍历，记录目前为止最远可以到达的地方
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end = nums.size() - 1;
        int reach = 0;
        int i = 0;
        while(reach < end && i <= reach) {
            reach = max(reach, nums[i] + i);
            i ++;
        }
        if(reach >= end)
            return true;
        return false;
    }
};

//回溯超时
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        vector<bool> ifVisited(size, false);
        return ifJump(nums, ifVisited, 0);
    }
    bool ifJump(vector<int>& nums, vector<bool> ifVisited, int pos) {
        if(pos == nums.size() - 1)
            return true;
        if(ifVisited[pos])
            return false;
        ifVisited[pos] = true;
        if(nums[pos] > nums.size())
            nums[pos] = nums.size();
        int i = 1;
        while(i <= nums[pos]) {
            if(ifJump(nums, ifVisited, (pos + i) % nums.size()))
                return true;
            i ++;
        }
        return false;
    }
};
