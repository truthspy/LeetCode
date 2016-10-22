// 还可以用priority_queue做
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findK(nums, 0, nums.size() - 1, k);
    }
    int findK(vector<int>& nums, int l, int r, int k) {
        int pivot = nums[l];
        int ll = l;
        int rr = r;
        while(ll < rr) {
            while(rr > ll && nums[rr] >= pivot)
                rr --;
            if(rr > ll && nums[rr] < pivot) {
                nums[ll] = nums[rr];
            }
            while(ll < rr && nums[ll] <= pivot)
                ll ++;
            if(ll < rr && nums[ll] > pivot) {
                nums[rr] = nums[ll];
            }
        }
        nums[ll] = pivot;
        int len2 = r - ll + 1;
        if(len2 == k)
            return pivot;
        if(len2 > k)
            return findK(nums, ll + 1, r, k);
        else
            return findK(nums, l, ll - 1, k - len2);
    }
};
