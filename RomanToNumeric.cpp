
#include<iostream>
#include<unordered_map>
using namespace std;

void romanToNumeric(string roman, int n) {
    unordered_map <char, int> symbols;
    symbols.insert({'I', 1});
    symbols.insert({'V', 5});
    symbols.insert({'X', 10});
    symbols.insert({'L', 50});
    symbols.insert({'C', 100});
    symbols.insert({'D', 500});
    symbols.insert({'M', 1000});
    int num = 0;
    int i=0;
    if(n == 1) {
        num = symbols[roman[i]];
        return;
    }
    while(i<n) {
            if(symbols[roman[i]] < symbols[roman[i+1]]) {
                num -= symbols[roman[i]];
               
            }
            else {
                num += symbols[roman[i]];
            }
            i= i+1;
    }
    cout<<num;
}

int main() {
    string roman = "";
    cout<<"Enter the roman number \n";
    cin>>roman;
    int len = roman.length();
    romanToNumeric(roman, len);
    
    return 0;
}