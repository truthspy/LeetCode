/**
 * Method1: from discuss
 * TODO
 * Binary Indexed Tree 树状数组
 * TODO
 * 还可以用Segment Tree，没看
 */
class NumArray {
public:
    NumArray(vector<int> &nums) {
        
    }

    void update(int i, int val) {
        
    }

    int sumRange(int i, int j) {
        
    }
};
/**
 * Method2：可AC，但是比较慢
 */
/*
class NumArray {
private:
    vector<int> curNums;
    vector<int> curSum;
    int size;
public:
    NumArray(vector<int> &nums) {
        size = nums.size();
        if(size == 0)
            return;
        curSum.resize(size);
        curNums.resize(size);
        curNums[0] = nums[0];
        curSum[0] = nums[0];
        for(int i = 1; i < size; i ++) {
            curNums[i] = nums[i];
            curSum[i] = curSum[i - 1]+ curNums[i];
        }
    }

    void update(int i, int val) {
        int diff = val - curNums[i];
        curNums[i] = val;
        for(int j = i; j < size; j ++)
            curSum[j] += diff;
    }

    int sumRange(int i, int j) {
        if(i == 0)
            return curSum[j];
        else
            return curSum[j] - curSum[i - 1];
    }
};
*/


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
