class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums12;
        //注意vector用法：
        //未放入数据之前不能使用[]取值，放入数据用push_back
        int pos1 = 0;
        int pos2 = 0;

        while(pos1 < m && pos2 < n) {
            if(nums1[pos1] < nums2[pos2]) {
                nums12.push_back(nums1[pos1]);
                pos1 ++;
            }
            else {
                nums12.push_back(nums2[pos2]);
                pos2 ++;
            }
        }
        while(pos1 < m) {
            nums12.push_back(nums1[pos1]);
            pos1 ++;
        }
        while(pos2 < n) {
            nums12.push_back(nums2[pos2]);
            pos2 ++;
        }
        for(int i = 0; i < (m + n); i ++) {
            nums1[i] = nums12[i];
        }
    }
};
