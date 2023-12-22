#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Sort nums1 and nums2 into a two array sorted in non-decreasing order.

// Input: nums1 = [1,2,4,7,9], m = 5, nums2 = [3,5,6,8], n = 4
// Output: nums1 = [1,2,3,4,5], m=5, nums2 = [6, 7, 8, 9], n = 4


class Solution {
    private:
        void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int ind1, int ind2) {
            if(arr1[ind1] > arr2[ind2]) {
                swap(arr1[ind1], arr2[ind2]);
            }
        }
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int len = m + n;
            int gap = (len/2) + (len%2);
            while(gap > 0) {
                int left = 0;
                int right = left + gap;
                while(right < len) {
                    if(left < m && right >= m) {
                        swapIfGreater(nums1, nums2, left, right - m);
                    }
                    else if(left >= m) {
                        swapIfGreater(nums2, nums2, left-m, right-m);
                    }
                    else {
                        swapIfGreater(nums1, nums1, left, right);
                    }
                }
            } 
        }
};