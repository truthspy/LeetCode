void moveZeroes(int* nums, int numsSize) {
    if(numsSize == 0 || numsSize == 1)
        return numsSize;
    int i = 0;
    int len = 0;
    for(i = 0; i < numsSize; i ++) {
        if(nums[i] != 0) {
            nums[len] = nums[i];
            len ++;
        }
    }
    for(i = len; i < numsSize; i ++) {
        nums[i] = 0;
    }
}
