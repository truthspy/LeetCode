class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int len = len1 + len2;
        if(len % 2 == 1)
            return findKthElement(nums1, nums2, 0, len1 - 1, 0, len2 - 1, len / 2 + 1);
        else
            return (findKthElement(nums1, nums2, 0, len1 - 1, 0, len2 - 1, len / 2) + findKthElement(nums1, nums2, 0, len1 - 1, 0, len2 - 1, len / 2 + 1)) / 2.0;
    }
    int findKthElement(vector<int>& nums1, vector<int>& nums2, int l1, int r1, int l2, int r2, int k) {
        int len1 = r1 - l1 + 1;
        int len2 = r2 - l2 + 1;
        if(len1 > len2)
            return findKthElement(nums2, nums1, l2, r2, l1, r1, k);
        if(len1 == 0)
            return nums2[k - 1];
        if(k == 1)
            return min(nums1[l1], nums2[l2]);
        int pos1 = l1 + min(k / 2, len1) - 1;
        int pos2 = l2 + (k - min(k / 2, len1)) - 1;
        // 小的那个数可以不包含在内！
        if(nums1[pos1] < nums2[pos2])
            return findKthElement(nums1, nums2, pos1 + 1, r1, l2, pos2, k - min(k / 2, len1));
        else if(nums1[pos1] > nums2[pos2])
            return findKthElement(nums1, nums2, l1, pos1, pos2 + 1, r2, min(k / 2, len1));
        else
            return nums1[pos1];
    }
};
