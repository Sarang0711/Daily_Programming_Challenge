// Given a string of lowercase alphabets, count all possible substrings that has exactly k distinct characters.

#include <iostream>
#include<unordered_map>
using namespace std;

int countSubstring(string str, int k) {
    if(k == 0) {
        return 0;
    }
    unordered_map<char, int> frequency;
    int n = str.length();
    int count = 0;
    int left = 0;
    for(int i=0; i<n; i++) {
        frequency[str[i]]++;
        while(frequency.size() > k && left <= i) {
            int p = frequency[str[left]]--;
            if(p == 1) {
                frequency.erase(str[left]);
            }
            left++;
        }
        count += (i-left+1);
    }
    return count;
}

int main()
{
    string str = "xyzyxx";
    int k;
    cout << "Enter the number of characters that you have to include in substring \n";
    cin >> k;
    cout << "Total substrings with exactly "<< k << " distinct characters: ";
    cout<<countSubstring(str, k) - countSubstring(str, k-1)<<endl;

    //? Number of substrings with k distinct characters = (Number of substrings with at most k distinct characters) -  (Number of substrings with at most k-1 distinct characters)
    return 0;
}
