#include <iostream>
#include <cmath>
using namespace std;

// Time complexity: O(n)
void checkMember(int num)
{
    if (num == 0 || num == 1)
    {
        cout << "Number is a member of fibonacci series \n";
        return;
    }
    int n1 = 0;
    int n2 = 1;
    int temp;
    while (n2 < num)
    {
        temp = n1 + n2;
        n1 = n2;
        n2 = temp;
        if (n2 == num)
        {
            cout << "Number is a member of fibonacci series \n";
            return;
        }
    }
    cout << "Not a member of fibonacci series \n";
}

// Time Complexity: O(logn)
// ? A number is Fibonacci if and only if one or both of (5*n2 + 4) or (5*n2 – 4) is a perfect square
bool isPerfectSquare(int n)
{
    int s = sqrt(n);
    return (s * s == n);
}
bool checkFibonacci(int num)
{
    return (isPerfectSquare(5 * num * num + 4) || isPerfectSquare(5 * num * num - 4));
}
int main()
{
    int num;
    cout << "Enter the number that is to be checked \n";
    cin >> num;
    checkMember(num);

    if (checkFibonacci(num)){
        cout << "Number is a member of fibonacci series \n";
    }
    else {
        cout<<"Not a member of fibonacci series \n";
    }
    return 0;
}

// Given a number N, figure out if it is a member of the fibonacci series or not. Return true if the number of members of the fibonacci series else false.
