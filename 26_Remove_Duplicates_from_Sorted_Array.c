int removeDuplicates(int* nums, int numsSize) {
    if(numsSize == 0 || numsSize == 1)
        return numsSize;
    int i = 1;
    int len = 1;
    int lastNum = nums[0];
    for(i = 1; i < numsSize; i ++) {
        if(nums[i] != lastNum) {
            lastNum = nums[i];
            nums[len] = nums[i];
            len ++;
        }
    }
    return len;
}
