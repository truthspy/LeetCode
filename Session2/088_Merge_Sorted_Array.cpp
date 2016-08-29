class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //从后往前会少去复制的环节
        if(n == 0)
            return;
        int i = m - 1, j = n - 1, pos = m + n - 1;
        while(i >= 0 && j >= 0) {
            if(nums1[i] >= nums2[j]) {
                nums1[pos] = nums1[i];
                i --;
            }
            else {
                nums1[pos] = nums2[j];
                j --;
            }
            pos --;
        }
        while(j >= 0) {
            nums1[pos] = nums2[j];
            j --;
            pos --;
        }
    }
};
/*
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0)
            return;
        for(int i = m - 1; i >= 0; i --) {
            nums1[i + n] = nums1[i];
        }
        int i = n, j = 0;
        int pos = 0;
        while(i < (m + n) && j < n) {
            if(nums1[i] <= nums2[j]) {
                nums1[pos] = nums1[i];
                i ++;
            }
            else {
                nums1[pos] = nums2[j];
                j ++;
            }
            pos ++;
        }
        while(j < n) {
            nums1[pos] = nums2[j];
            j ++;
            pos ++;
        }
    }
};*/
