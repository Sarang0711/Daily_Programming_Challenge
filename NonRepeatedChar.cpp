// Given a string, find the first non-repeated character in it. If no such character exists, return a specific value (e.g., a special character or -1) to indicate that no non-repeated character is found.

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

char nonrepeatedchar(string str, int n) {
    unordered_map<char, int> characters;
    vector<char> order;
    for(auto &ch: str) {
        characters[ch]++;
        order.push_back(ch);
    }
    for(const int &key: order) {
       if(characters[key] == 1) {
            return key;
       }
    }
    return -1;
}
int main() {
    string str = "insertionorder";
    int len = str.length();
    cout<<"First non repeating character in string "<<str<<" is "<<nonrepeatedchar(str, len);
    return 0;
}