class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        priority_queue<int> maxHeap;
        k = size - k + 1;
        int i = 0;
        while(i < k && i < size) {
            maxHeap.push(nums[i]);
            i ++;
        }
        while(i < size) {
            if(maxHeap.top() > nums[i]) {
                maxHeap.pop();
                maxHeap.push(nums[i]);
            }
            i ++;
        }
        return maxHeap.top();
    }
};
