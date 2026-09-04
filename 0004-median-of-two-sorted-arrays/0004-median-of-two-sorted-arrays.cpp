class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n3 = n1 + n2;
        vector<int> nums3;
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) {
                nums3.push_back(nums1[i]);
                i++;
            } else {
                nums3.push_back(nums2[j]);
                j++;
            }
        }
        while (i < n1) {
            nums3.push_back(nums1[i]);
            i++;
        }
        while (j < n2) {
            nums3.push_back(nums2[j]);
            j++;
        }
        if (n3 % 2 != 0) {
            return nums3[n3 / 2];
        } else {
            return (double)((double)nums3[n3 / 2] +
                            (double)nums3[(n3 / 2) - 1]) /
                   2;
        }
    }
};
