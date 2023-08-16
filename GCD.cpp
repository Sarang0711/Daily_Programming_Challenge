// Find the GCD (Greatest Common Divisor) of 2 integers. The GCD of any 2 numbers is the largest number that divides both the integers.

#include<iostream>
using namespace std;

// Naive Approach
int findGcd(int num1,int num2) {
    int min = 0;
    int max = 0;
    if(num1 > num2) {
        min = num2;
        max = num1;
    }
    else {
        min = num1;
        max = num2;
    }
    if(max % min == 0) {
        return min;
    } 
    for(int i=min; i>= 2; i--) {
        if(min % i == 0 && max % i == 0) {
            return i;
        }
    }
    return 1;

}

// Euclidean Method 
int Gcd(int n1, int n2) {
    while(n1 > 0 && n2 > 0) {
        if(n1 > n2) {
            n1 = n1 % n2;
        }
        else {
            n2 = n2 % n1;
        }
    }
    if(n1 == 0) {
        return n2;
    }
    return n1;
}
int main()  {
    int num1, num2;
    cout<<"Enter the two numbers \n";
    cin>>num1;
    cin>>num2;
    cout<<findGcd(num1, num2)<<endl;
    cout<<"using Euclidean method "<<Gcd(num1, num2);
    return 0;
}