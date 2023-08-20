// Given a sequence of n strings, the task is to check if any two similar words come together and then destroy each other then print the number of words left in the sequence after this pairwise destruction.

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int removeConsecutive(vector<string> &str) {
    int n = str.size();
    for(int i=0; i<n-1; ) {
        if(str[i].compare(str[i+1]) == 0) {
            str.erase(str.begin()+i);
            str.erase(str.begin()+i);
            // Erase function delete the element and also shifts other element that's why i is not updated
            if(i > 0) {
                i--;
            }
            n = n-2;
        } 
        else {
            i++;
        }
    }
    return str.size();
}
int main() {
    vector<string> str = {"ab", "aa", "aa", "bcd", "ab"};
    cout<<"The number of strings after removing consecutive "<<removeConsecutive(str);
    return 0;
}

