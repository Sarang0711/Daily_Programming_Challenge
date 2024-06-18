class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN;
        // the prefix will start from the starting of the array and the suffix is started from end
        int n= nums.size();
        if(n == 1) {
            return nums[0];
        }
        int prefix = 1;
        int suffix = 1;
        int mod = 1e9;
        for(int i=0; i<n; i++) {
           if(prefix == 0) {
            prefix = 1;
           }
           if(suffix == 0) {
            suffix = 1;
           }
           prefix *= nums[i];
           suffix *= nums[n-i-1];
           maxi = max(maxi, max(prefix, suffix));
           prefix = prefix % mod;
           suffix = suffix % mod;
        }
        return maxi;
    }
};