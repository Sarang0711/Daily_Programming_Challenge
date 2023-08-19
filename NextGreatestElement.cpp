#include<iostream>
#include<vector>
using namespace std;

vector<int> nextGreatest(vector<int> arr) {
    vector<int> ans;
    int flag;
    for(int i=0; i<arr.size(); i++) {
        flag = 0;
        for(int j=i+1; j<arr.size(); j++) {
            if(arr[i] < arr[j]) {
                ans.push_back(arr[j]);
                flag = 1;
                break;
            }
        }
        if(!flag) {
            ans.push_back(-1);            
        }
        
    }
    return ans;
}
int main() {
    vector <int> arr = {10, 7, 8, 6, 9};
    vector<int> ans = nextGreatest(arr);
    vector<int>::iterator ptr;
    for(ptr = ans.begin(); ptr<ans.end(); ptr++) {
        cout<< *ptr<<" ";
    }
    return 0;
}