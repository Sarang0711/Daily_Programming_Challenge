class Solution {
public:

    int findFirstPosition(vector<int>&nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int index = -1;
        while(start <= end) {
            int mid = (start + end) / 2;
            if(nums[mid] == target) {
                // as we got our target now we need to go on left 
                // because we want to find first position of target that is no left side
                index = mid;
                end = mid - 1;
            }
            else if (nums[mid] > target) {
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return index;
    }

    int findLastPosition(vector<int>&nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int index = -1;
        while(start <= end) {
            int mid = (start + end) / 2;
            if(nums[mid] == target) {
                // as we got our target now we need to go on right 
                // because we want to find last position of target that is no right side
                index = mid;
                start = mid + 1;
            }
            else if (nums[mid] > target) {
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return index;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
       int firstPosition = -1;
       int lastPosition = -1;
       firstPosition = findFirstPosition(nums, target);
       lastPosition = findLastPosition(nums, target);

        return {firstPosition, lastPosition};
    }
};