//看discuss后解答：
//不是链表，可以从后往前倒着合并
//这样一定不会覆盖掉nums1中的原有数据
//最后拷贝剩余部分可以只考虑nums2情况
//复杂度o(m+n)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos1 = m - 1;
        int pos2 = n - 1;
        int pos = m + n - 1;
        while(pos1 >= 0 && pos2 >= 0) {
            if(nums1[pos1] > nums2[pos2]) {
                nums1[pos] = nums1[pos1];
                pos1 --;
            }
            else {
                nums1[pos] = nums2[pos2];
                pos2 --;
            }
            pos --;
        }
        while(pos2 >= 0) {
            nums1[pos] = nums2[pos2];
            pos2 --;
            pos --;
        }
    }
};
