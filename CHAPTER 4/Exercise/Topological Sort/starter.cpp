#include <bits/stdc++.h>
using namespace std;

//Adj_MAT implementation
//O(V^2)
void dfs_ADJ_MAT(int start, vector<vector<int>> &ADJ_MAT, vector<int> &V, vector<int> &ts){
    V[start] = 1;

    for(int i = 0; i < V.size();i++){
        if(ADJ_MAT[start][i] != 0 && V[i] == -1){
            dfs_ADJ_MAT(i,ADJ_MAT, V,ts);
        }
    }
    ts.push_back(start);
}

void dfs_ADJ_LST(int start, vector<vector<int>> &ADJ_LST, vector<int> &V, vector<int> &ts){
    V[start] = 1;

    for(int i = 0; i < ADJ_LST[start].size();i++){
        if(V[ADJ_LST[start][i]] == -1)
            dfs_ADJ_LST(ADJ_LST[start][i],ADJ_LST, V, ts);
    }
    ts.push_back(start);
}


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N = 4;
  
    vector<vector<int>> ADJ_MAT{
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,1,0,0},
        {0,1,0,0,0,0},
        {1,1,0,0,0,0},
        {1,0,1,0,0,0}
    };
    vector<int> visted = vector<int>(ADJ_MAT.size(),-1);
    vector<vector<int>> ADJ_LST{
        {},
        {},
        {3},
        {1},
        {0,1},
        {2,0}
    };
    cout<<"Topological sort using Adjecency Matrixs:\n";
    vector<int> ts;

    for(int i = 0; i < ADJ_MAT.size();i++){
        
        if(visted[i] == -1){
            dfs_ADJ_MAT(i,ADJ_MAT, visted,ts);
        }
    }
    for(int i = ts.size()-1;i > -1; i--){
        cout<<ts[i]<<" ";
    }
    cout<<"\n";

    visted = vector<int>(ADJ_LST.size(),-1);
    cout<<"Topological sort using Adjecency List:\n";
    
    ts = vector<int>();

    dfs_ADJ_LST(0,ADJ_LST, visted,ts);
    for(int i = 0; i < ADJ_LST.size();i++){
        if(visted[i] == -1)
            dfs_ADJ_LST(i,ADJ_LST, visted,ts);
    }
    for(int i = ts.size()-1;i > -1; i--){
        cout<<ts[i]<<" ";
    }
    
    cout<<"\n";

}