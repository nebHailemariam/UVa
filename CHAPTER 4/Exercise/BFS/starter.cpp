#include <bits/stdc++.h>
using namespace std;

//Adj_MAT implementation
//O(V^2)
void bfs_ADJ_MAT(int start, vector<vector<int>> &ADJ_MAT, vector<int> &V){
    queue<int> q;
    q.push(start);
    int layer = 0;
    cout<<"Layer "<<layer<<", visite "<<start<<"\n";
    V[start]  = 0;
    while(!q.empty()){
        int u = q.front();

        q.pop();
        layer++;
        cout<<"Layer "<<layer;
        for(int v = 0;v < ADJ_MAT.size();v++){
            if(ADJ_MAT[u][v] != 0 && V[v] == -1){
                q.push(v);
                V[v] = V[u]+1;   
                cout<<", visite "<<v;
            }
        }
        cout<<"\n";
        
    }
}

void bfs_ADJ_LST(int start, vector<vector<int>> &ADJ_LST, vector<int> &V){
    queue<int> q;
    q.push(start);
    int layer = 0;
    V[start] = 0;
    cout<<"Layer "<<layer<<", visite "<<start<<"\n";
    while(!q.empty()){
        int u = q.front();
        q.pop();
        layer++;
        cout<<"Layer "<<layer;
        for(int v = 0;v < ADJ_LST[u].size();v++){
            if( V[ADJ_LST[u][v]] == -1){
                q.push(ADJ_LST[u][v]);
                V[ADJ_LST[u][v]] = V[u]+1;
                cout<<", visite "<<ADJ_LST[u][v];
            }
        }
        cout<<"\n";
        
    }
}


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N = 4;
    
    vector<vector<int>> ADJ_MAT{
        {0,1,0,1},
        {1,0,0,0},
        {0,0,0,0},
        {0,0,1,0}
    };
    vector<int> visited = vector<int>(ADJ_MAT.size(),-1);
    vector<vector<int>> ADJ_LST{
        {1,3},
        {0},
        {},
        {2}
    };
    cout<<"Adjecency Matrixs:\n";
    bfs_ADJ_MAT(0,ADJ_MAT, visited);
    cout<<"\n";
    visited = vector<int>(ADJ_LST.size(),-1);
    cout<<"Adjencency List:\n";
    bfs_ADJ_LST(0,ADJ_LST, visited);

}