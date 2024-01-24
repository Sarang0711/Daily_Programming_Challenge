        #include<iostream>
        #include<vector>
        using namespace std;
        
        class Solution {
    private:
        void merge(vector<int> &nums, int start, int mid, int end) {
            vector<int>temp;

            int left = start;
            int right = mid + 1;
            
            while(left <= mid && right <= end) {
                if(nums[left] <= nums[right]) {
                    temp.push_back(nums[left]);
                    left++;
                }
                else {
                    temp.push_back(nums[right]);
                    right++;
                }
            }
            while(left <= mid) {
                temp.push_back(nums[left]);
                left++;
            }
            while(right <= end) {
                temp.push_back(nums[right]);
                right++;
            }

            for(int i=start; i<=end; i++) {
                nums[i] = temp[i-start];
            }
            
        }

        int countPairs(vector<int> &nums, int start, int mid, int end) {
            int j = mid+1;
            int cnt = 0;
            for(int i=start; i<= mid; i++) {
                while(j <= end && nums[i] > 2*(long long)nums[j]) {
                    j++;
                }
                cnt += j -(mid + 1);
            }
            return cnt;
        }
        int mergeSort(vector<int> &nums,int start, int end) {
            int cnt =0;
            if(start >= end) {
                return cnt;
            }

            int mid = (start + end ) / 2;
            cnt += mergeSort(nums, start, mid);
            cnt += mergeSort(nums, mid+1, end);
            cnt += countPairs(nums, start, mid, end);
            merge(nums, start, mid, end);
            return cnt;
        }

    public:
        int reversePairs(vector<int>& nums) {
            int n = nums.size()-1;
            int cnt = mergeSort(nums, 0, n);
            return cnt;
        }
    };

    int main() {
        vector<int> a = {2,4,3,5,1};
    int n = 5;
    Solution s1;
    
    int cnt = s1.reversePairs(a);
    cout << "The number of reverse pair is: "
         << cnt << endl;
        return 0;
    }