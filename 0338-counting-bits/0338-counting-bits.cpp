class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        ans[0] = 0;
        // ans[1] = 1;
        for(int i=1; i<=n; i++) {
            // if(i % 2 == 0) {
            //     ans[i] = ans[i/2];
            // }
            // else {
            //     ans[i] = ans[i/2] + 1;
            // }
            ans[i] = ans[i/2] + i % 2;
        }
        return ans;
    }
};