
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
    int temp;
    int i=0;
    while(i<n) {
        if(n == 1) {
            num = symbols[roman[i]];
            break;
        }
            int j = i+1;
            if(j > n) {
                num = num + symbols[roman[i]];
                cout<<num<<"1st if \n";
                break;
            }
            if(symbols[roman[i]] < symbols[roman[j]]) {
                temp = symbols[roman[j]] - symbols[roman[i]];
                cout<<temp<<" 2nd  if \n";

            }
            else {
                temp = symbols[roman[i]] + symbols[roman[j]];
                cout<<temp<<" else part \n";
            }

            i= j+1;
            cout<<"i val "<<i<<endl;
 
            num = num + temp;
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