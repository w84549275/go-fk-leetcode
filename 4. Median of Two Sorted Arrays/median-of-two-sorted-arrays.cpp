#include <stdlib.h>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size()){
            /* always dichotomize the smaller vector */
            return findMedianSortedArrays(nums2, nums1);
        }
        int low = 0;
        int high = nums1.size();
        int cut_1, cut_2;
        while (low <= high){
            cut_1 = (low + high) / 2;
            cut_2 = nums1.size() + nums2.size() - cut_1;

            if (nums1[cut_1] < nums2[cut_2 - 1]){
                low = cut_1 + 1;
            }
            else if (nums1[cut_1 - 1] > nums2[cut_2]){
                high = cut_1 - 1;
            }
            else break;
        }
        if ((nums1.size() + nums2.size()) / 2 == 0){
            return (max(nums1[cut_1 - 1], nums2[cut_2 - 1]) + min(nums1[cut_1], nums2[cut_2])) / 2;
        }
        else{
            return max(nums1[cut_1 - 1], nums2[cut_2 - 1]);
        }
    }
};