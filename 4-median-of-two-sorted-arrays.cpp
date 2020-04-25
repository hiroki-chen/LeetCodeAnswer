/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1_length = nums1.size();
        int nums2_length = nums2.size();
        if(nums1_length > nums2_length) return findMedianSortedArrays(nums2, nums1);

        int nums1_LMAX, nums1_RMIN, nums2_LMAX, nums2_RMIN, c1, c2;
        int i = 0, j = 2 * nums1_length;
        while(i <= j){
            c1 = (i + j) / 2; 
            c2 = nums1_length +  nums2_length - c1;
            nums1_LMAX = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
            nums1_RMIN = (c1 == 2 * nums1_length) ? INT_MAX : nums1[c1 / 2];
            nums2_LMAX = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
            nums2_RMIN = (c2 == 2 * nums2_length) ? INT_MAX : nums2[c2 / 2];
            if(nums1_LMAX > nums2_RMIN) j = c1 - 1;
            else if(nums2_LMAX > nums1_RMIN) i = c1 + 1;
            else break; //两个数组的左边元素均小于右边元素了。
        }
        return (max(nums1_LMAX, nums2_LMAX) + min(nums1_RMIN, nums2_RMIN)) / 2.0;
     }
};