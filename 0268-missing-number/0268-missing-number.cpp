class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalSum = n*(n+1)/2;
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
        }
        return totalSum - sum;




        // unordered_map<int, int>umap;
        // for(int i=0; i<n; i++) {
        //     umap[nums[i]]++;
        // }
        // for(int i=0; i<=n; i++) {
        //     if(umap.find(i) == umap.end()) {
        //         return i;
        //     }
        // }
        // return -1;
    }
};