int removeElement(int* nums, int numsSize, int val) {
    int end = numsSize - 1;
    int i = 0;
    while(i <= end) {
        if(nums[i] == val) {
            nums[i] = nums[end];
            end --;
        }
        else
            i ++;
    }
    return end + 1;
}
