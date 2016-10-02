/**
 * Method1: 先排序，然后1&2交换，3&4交换，5&6交换，以此类推
 * Method2：从头往后遍历，可知如果i为奇数，n[i] >= n[i-1]，偶数，n[i]<=n[i-1]
 * 如果为奇数,n[i] < n[i-1]，由于已经满足n[i-1] < n[i-2]，则n[i]<n[i-2]，可交换n[i]和n[i-1]
 * 偶数同理
 */
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i < n; i ++) {
            if(i % 2 == 1 && nums[i] < nums[i - 1])
                swap(nums[i], nums[i - 1]);
            else if(i % 2 == 0 && nums[i] > nums[i - 1])
                swap(nums[i], nums[i - 1]);
        }
    }
};
