// ? How do you check if two strings are anagrams of each other?

#include<iostream> 
#include<unordered_map>
using namespace std;


bool isAnagram(string s, string t) {
        unordered_map<char, int>letters;
        if(s.length() != t.length()) {
            return false;
        }

        for(auto ch: s) {
            letters[ch]++;
        }
        cout<<"Unordered map is as follows \n";
         for (auto x : letters) {            //? If you want to display the unordered map
            char key = x.first;  
            int val = x.second;
            cout<<key<<" "<<val<<"\n";
        }
        for(auto ch: t) {
            letters[ch]--;
        }
        for (auto x : letters) {       
           if(x.second != 0) {
            return false;
           }
        }
        return true;
    }

int main() {
    string str1 = "listen";
    string str2 = "silent";
    if(isAnagram(str1, str2)) {
        cout<<"The strings is an anagram of other string \n";
    }
    else {
        cout<<"The string is not an anagram of the other string \n";
    }
    return 0;
}

// String 1: "listen"
// String 2: "silent"
// Expected Output: True

// An anagram of a string is another string that uses the same characters, but the order of characters can be different