class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>st;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(st.find(nums[i]) == st.end()) {
                st.insert(nums[i]);
            }
            else {
                return true;
            }
            
        }
        return false;
        
    }
};