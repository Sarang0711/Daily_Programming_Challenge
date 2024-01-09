#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Item{
    int wt;
    int pft;
    Item(int weight, int profit) {
        wt = weight;
        pft = profit;
    }
};

void knapsack(int wt[], int pft[], int n, int cap) {
    vector<float> pw_ratio(n);
    for(int i=0; i<n; i++) {
        float k = static_cast<float>(pft[i]) / wt[i];
        pw_ratio[i] = k;
    }
    sort(pw_ratio.begin(), pw_ratio.end(), greater<float>());
    int rem = cap;
    

}

int main() {
    int weights[] = {2, 3, 4, 7, 1, 4, 1};
    int profits[] = {10, 5, 15, 7, 6, 18, 3};
    int n = sizeof(weights)/sizeof(weights[0]);
    int M = 15;
    knapsack(weights, profits, n, M);
    return 0;
}