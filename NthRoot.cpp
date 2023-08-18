#include <iostream>
#include<cmath>
using namespace std;

int NthRoot(int N, int M) {
    // N = 3 and M = 27
    float ans = exp(log(M)/N);
    // cout<<ans<<endl;
    int result = ans;
    if(result == ans) {
        return result;
    }
    return -1;
}

int main()
{
    int N, M;
    cout<<"Enter the value of M (M is the number of which Nth root to be calculated) \n";
    cin >> M;
    cout << "Enter the value of N (Nth root) \n";
    cin >> N;
    cout<<NthRoot(N, M);
    return 0;
}

// You are given two positive numbers N and M. You have to return the Nth root of M. If the Nth root of M is not an integer, return -1.
// Nth root of an integer M is a number, which, raised to the power N, gives M as a result
