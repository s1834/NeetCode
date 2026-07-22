class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // we need nums1 size to be smaller
        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);
       
        int n = nums1.size(), m = nums2.size();
        int left = 0, right = n, total = n + m, half = (total + 1) / 2; 

        while(left <= right) {
            int mid1 = left + (right - left) / 2; // nums1
            int mid2 = half - mid1; // nums2

            // nums1
            int nums1Left = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int nums1Right = (mid1 == n) ? INT_MAX : nums1[mid1];

            // nums2
            int nums2Left = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int nums2Right = (mid2 == m) ? INT_MAX : nums2[mid2];

            // if partition correct
            if(nums1Left <= nums2Right && nums2Left <= nums1Right) {
                if(total % 2) return max(nums1Left, nums2Left); // odd
                else return (max(nums1Left, nums2Left) + min(nums1Right, nums2Right)) / 2.0; // even
            } else if(nums1Left > nums2Right) right = mid1 - 1;
            else left = mid1 + 1;
        }

        return 0.0;
    }
};