#include <iostream>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }
    unordered_map<char, int> letters;
    for (auto ch : s)
    {
        letters[ch]++;
    }
    cout << "Unordered map is as follows \n";
    // for (auto ch : letters)
    // {
    //     cout << ch.first << "  " << ch.second << endl;
    // }
    for(auto ch: t) {
        letters[ch]--;
    }
    for(auto ch: letters) {
        if(ch.second != 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "listen";
    string t = "silent";
    if(isAnagram(s, t)) {
        cout<<"String is anagram \n";
    }
    else {
        cout <<"Not an anagram \n";

    }
    return 0;
}