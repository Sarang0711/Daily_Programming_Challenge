// Desc
// Given a string s, find the length of the longest 
// substring without repeating characters.

// Sol
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<string.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        unordered_map<char, int>charMap;
        int maxi = 0;
        int left = 0;
        for(int right=0; right<str.length(); right++) {

            if(charMap.find(str[right]) == charMap.end() || charMap[str[right]] < left) {
                charMap[str[right]] = right;
                maxi = max(maxi, right-left+1);
            }
            else {
                left = charMap[str[right]] + 1;
                charMap[str[right]] = right;
            }
        }
        return maxi;
    }
};