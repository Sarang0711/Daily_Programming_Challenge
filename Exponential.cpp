#include <iostream>
#include<vector>
using namespace std;

// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

// Sol 1:
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n < 0) {
            n = abs(n);
            x = 1/x;
        }
        if(n % 2 == 0) {
            return myPow(x*x, n/2);
        }
        else {
            return x * myPow(x, n-1);
        }
        
    }
};

// Sol 2:
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long nn = abs(n);
        while(nn > 0) {
            if(nn % 2 == 1) {
                ans = ans*x;
                nn = nn-1;
            }
            else {
                x = x * x;
                nn = nn / 2;
            }
        }
        if(n < 0) {
            ans = 1.0 / ans;
        }
        return ans;
    }
};