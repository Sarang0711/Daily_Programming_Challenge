#include<iostream>
#include<unordered_map>
using namespace std;

bool isIsomorphic(string s, string t) {
            unordered_map<char, char> iso1;
            unordered_map<char, char> iso2;
            if(s.length() != t.length()) {
                return false;
            }
            int n = s.length();
            for(int i=0; i<n; i++) {
                char ch = s[i];
                if(iso1.find(ch) == iso1.end()) {
                    iso1[ch] = t[i];
                }
                char ch1 = t[i];
                if(iso2.find(ch1) == iso2.end()) {
                    iso2[ch1] = s[i];
                }

            }
            for(int i=0; i<n; i++) {
                char ch= s[i];
                if(iso1[ch] != t[i]) {
                    return false;
                }
                char ch1= t[i];
                if(iso2[ch1] != s[i]) {
                    return false;
                }
            }
            return true;
        }

int main() {
    string str1 = "aab";
    string str2 = "xxy";
    isIsomorphic(str1, str2);
    return 0;
}

// Check whether two string are isomorphic.
// Two strings are isomorphic if one-to-one mapping is possible for every character of first string to every character of second string while preserving the orders of the characters.

// Input : str1 = "aab", str2 = "xxy"
// Output = 1 or isomporphic.