class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> win;
        int size = nums.size();
        vector<int> res;
        for(int i = 0; i < size; i ++) {
            while(!win.empty()) {
                if(nums[win.back()] <= nums[i])
                    win.pop_back();
                else
                    break;
            }
            win.push_back(i);
            if(i >= k) {
                if(win.front() == (i - k))
                    win.pop_front();
            }
            if(i >= (k - 1))
                //存的是下标，压入的是数字
                res.push_back(nums[win.front()]);
        }
        return res;
    }
};
