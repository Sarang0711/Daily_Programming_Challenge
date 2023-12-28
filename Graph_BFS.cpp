#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<vector<int>> &adj, int currVertex, vector<bool> &visited) {
  queue<int> que;
  
}
int main() {
  vector<vector<int>>adj = {
    {0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 1},
    {0, 1, 1, 0, 0, 1},
    {0, 0, 0, 1, 1, 0}
  };
  int n = adj.size();
  vector<bool>visited(n, false);
  
  for(int i=0; i<adj.size(); i++) {
    if(!visited[i]) {
      BFS(adj, i, visited); 

    }
  }
  return 0;
}