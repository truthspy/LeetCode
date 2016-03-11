/**
 * from Internet
 * Condensed mathematical description:
 * Find largest index i such that array[i − 1] < array[i].
 * Find largest index j such that j ≥ i and array[j] > array[i − 1].
 * Swap array[j] and array[i − 1].
 * Reverse the suffix starting at array[i].
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return;
        int i = size - 2;
        while(i >= 0) {
            if(nums[i] < nums[i + 1])
                break;
            i --;
        }
        int pos1= i;
        if(i == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        i ++;
        while(i < size) {
            if(nums[i] <= nums[pos1]) //注意等于号，eg:1,5,1->5,1,1，如果没等于号则还是1,5,1
                break;
            i ++;
        }
        int pos2 = i - 1;
        swap(nums[pos1], nums[pos2]);
        reverse(nums.begin() + pos1 + 1, nums.end());
        
    }
};
