#include<iostream>
using namespace std;
 
class Graph
{
    private:
        int mat[10][10];
        int n;
         
    public:
        Graph()
        
        {
            cout<<"Enter the number of nodes to be inserted \n";
            cin>>n;
            for(int i=1; i<= n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    mat[i][j] = 0;
                }
            }
 
        }
        void create()
        {
            int startv, endv, cost;
            int ans;
            
            do
            {
                cout<<"Enter the starting and ending vertex \n";
                cin>>startv;
                cin>>endv;
                cout<<"Enter the cost of the edge between above vertices \n";
                cin>>cost;
                mat[startv][endv] = cost;
                //mat[endv][startv] = cost;
                cout<<"Do you want to add one more edge (1\\0)\n";
                cin>>ans;
            }
            while(ans == 1);
        }
        void display()
        {
            for(int i =1; i<= n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    cout<<mat[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        void shortest_path()
        {
            for(int k=1; k<=n; k++)
            {
                for(int i=1;i<=n; i++)
                {
                    for(int j=1; j<=n; j++)
                    {
                        if(i != j)
                        {
                            if(mat[i][j] != 0 && mat[i][j] > mat[i][k] + mat[k][j])
                            {
                                mat[i][j] = mat[i][k] + mat[k][j];
                            }
                        }
                    }
                }
            }
        }
        
};
 
int main() {
    Graph g1;
    g1.create();
    cout<<"Before applying shortest path algorithm \n";
    g1.display();
    g1.shortest_path();
    cout<<"After applying shortest path algorithm \n";
    g1.display();
    return 0;
}