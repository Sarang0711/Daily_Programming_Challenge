class Solution {
public:
    bool search(vector<int>& nums, int target) {
       int n = nums.size();
       int left = 0;
       int right = n-1;
       while(left <= right){
            int mid = (left + right)/2;
            if (nums[mid] == target){
                return true;
            }
            if(nums[left]==nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
                continue;
            }
            if (nums[left] <= nums[mid]) {
                // left half is sorted
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else if (nums[right] >= nums[mid]){
                if (target > nums[mid] && nums[right]>= target) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
       }
            
    return false;

    }
};