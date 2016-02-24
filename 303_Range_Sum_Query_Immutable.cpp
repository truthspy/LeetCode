class NumArray {
public:
    vector<int> curSum;
    NumArray(vector<int> &nums) {
        int size = nums.size();
        int sum = 0;
        for(int i = 0; i < size; i ++) {
            sum += nums[i];
            curSum.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        if(i == 0) {
            return curSum[j];
        }
        return (curSum[j] - curSum[i - 1]);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
