#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Graph
{
    private:
        int graph[10][10];
        int n;
        queue<int> que;
        stack<int> stk;
        
    public:
        void bfs();
        void dfs();
        Graph()
        {
            cout<<"Enter the number of nodes to be inserted \n";
            cin>>n;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    graph[i][j] = 0;
                }
            }
        }
        
        void create()
        {
            int startv, endv;
            int ans;
            
            do
            {
                cout<<"Enter the starting and ending vertex \n";
                cin>>startv;
                cin>>endv;
                graph[startv][endv] = 1;
                graph[endv][startv] = 1;
                cout<<"Do you want to add one more edge (1\\0)\n";
                cin>>ans;
            }
            while(ans == 1);
        }
        void display()
        {
            for(int i =0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    cout<<graph[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        
        
};

void Graph::bfs()
{
    int v;
    int visited[n];
    int explored[n];
    cout<<"Enter the starting vertex from which you want to start BFS traversal \n";
    cin>>v;
    visited[v] = 1;
    cout<<"The BFS traversal of graph is as follows \n";
    cout<<v<<"\t";
    for(int i= 1; i<n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(graph[v][j] == 1 && explored[j] != 1 && visited[j] != 1)
            {
                que.push(j);
                explored[j] = 1;
            }
        }
        v = que.front();
        que.pop();
        cout<<v<<"\t";
        explored[v] = 0;
        visited[v] = 1;
    }
}

void Graph::dfs()
{
    int v;
    int visited[n];
    int explored[n];
    cout<<"Enter the starting vertex from which you want to start DFS traversal \n";
    cin>>v;
    cout<<"The DFS traversal of graph is as follows \n";
    cout<<v<<"\t";
    visited[v] = 1;
    for(int i= 1; i<n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(graph[v][j] == 1 && explored[j] != 1 && visited[j] != 1)
            {
                stk.push(j);
                explored[j] = 1;
            }
        }
        v = stk.top();
        stk.pop();
        cout<<v<<"\t";
        visited[v] = 1;
    }
}

int main()
{
    Graph g1;
    g1.create();
    g1.display();
    //g1.bfs();
    g1.dfs();
    return 0;
}
