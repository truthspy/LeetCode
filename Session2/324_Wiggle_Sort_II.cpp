/**
 * @TODO follow-up
 */
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int n = nums.size();
        int i = (n - 1) / 2;
        int j = n - 1;
        int pos = 0;
        while(pos < n) {
            if(pos % 2 == 0) {
                nums[pos] = tmp[i];
                i --;
            }
            else {
                nums[pos] = tmp[j];
                j --;
            }
            pos ++;
        }
    }
};
