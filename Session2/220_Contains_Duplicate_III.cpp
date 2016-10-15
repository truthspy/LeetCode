class Solution {
public:
// 抄来的方法1：用一个set记录维护大小为k窗口中的所有元素，用lower_bound找大于等于nums[i]-t的最小元素，然判断是不是满足条件，
// 而且如果nums[i]-t到nums[i]没有元素的话，也可以找到比nums[i]大的元素，所以还需要再判断一下找到的数和nums[i]的绝对值差
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> mySet;
        int n = nums.size();
        for(int i = 0; i < n; i ++) {
            if(i > k)
                mySet.erase(nums[i - k - 1]);
            auto it = mySet.lower_bound(nums[i] - t);
            if(it != mySet.end() && abs(*it - nums[i]) <= t)
                return true;
            mySet.insert(nums[i]);
        }
        return false;
    }
// TODO Method2:
// 通排序的方法
/*Brute Force超时
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        for(int i = 0; i < n; i ++) {
            for(int j = i - 1; j >= 0 && (i - j) <= k; j --) {
                if(abs((long long)nums[i] - (long long)nums[j]) <= (long long)t)
                    return true;
            }
        }
        return false;
    }
    */
};
