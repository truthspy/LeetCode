/**
 * 看了答案
 * 大概思路是用双向队列保存数字的下标，遍历整个数组，
 * 如果此时队列的首元素是i - k的话，表示此时窗口向右移了一步，则移除队首元素。
 * 然后比较队尾元素和将要进来的值，如果小的话就都移除，然后此时我们把队首元素加入结果中即可
 * TODO 没太想清楚，再看
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> result;
        int size = nums.size();
        for(int i = 0; i < size; i ++) {
            if(!q.empty() && q.front() == i - k)
                q.pop_front();
            while(!q.empty() && nums[q.back()] <= nums[i])
                q.pop_back();
            q.push_back(i);
            if(i >= (k - 1))
                result.push_back(nums[q.front()]);
        }
        return result;
    }
};
