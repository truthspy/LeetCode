//洗牌问题
class Solution {
private:
    vector<int> data;
    vector<int> cur;
public:
    Solution(vector<int> nums) {
        data = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return data;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> cur = data;
        int i = cur.size();
        while(i > 0) {
            int pos = rand() % i;
            swap(cur[pos], cur[i - 1]);
            i --;
        }
        return cur;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
