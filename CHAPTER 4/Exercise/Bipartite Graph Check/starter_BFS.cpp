#include <bits/stdc++.h>
using namespace std;

//Adj_MAT implementation
//O(V^2)
bool bfs_ADJ_MAT(int start, vector<vector<int>> &ADJ_MAT, vector<int> &color){
    queue<int> q;
    q.push(start);

    color[start]  = 0;
    while(!q.empty()){
        int u = q.front();
        if(ADJ_MAT[u][u] != 0)
            return false;
        q.pop();
        for(int v = 0;v < ADJ_MAT.size();v++){
            if(ADJ_MAT[u][v] != 0 && color[v] == -1){
                q.push(v);
                color[v] =1 - color[u];
            }else if(ADJ_MAT[u][v] != 0 && color[v] == color[u]){
                return false;
            }
        }
    }
    return true;
}

bool bfs_ADJ_LST(int start, vector<vector<int>> &ADJ_LST, vector<int> &color){
    queue<int> q;
    q.push(start);

    color[0] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v = 0;v < ADJ_LST[u].size();v++){
            if( color[ADJ_LST[u][v]] == -1){
                q.push(ADJ_LST[u][v]);
                color[ADJ_LST[u][v]] = 1-color[u];
            }else if(color[ADJ_LST[u][v]] == color[u]){
                return false;
            }
        }

        
    }
    return true;
    
}


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> ADJ_MAT{
        {0,1,0,1},
        {1,0,1,0},
        {0,1,0,1},
        {1,0,1,0}
    };
    vector<vector<int>> ADJ_LST{
        {1,3},
        {0,2},
        {1,3},
        {0,2}
    };
    cout<<"Bipartite Check on Adjecency Matrixs:";

    vector<int> color = vector<int>(ADJ_MAT.size(),-1);
    bool is_bipartite = true;
    for(int i = 0; i < ADJ_MAT.size();i++){
        if(color[i] == -1){
        is_bipartite = bfs_ADJ_MAT(i,ADJ_MAT, color);
        if(is_bipartite == false)
            break;
        }
    }
    (is_bipartite)?cout<<" True.\n":cout<<"False.\n";
    
    cout<<"\n";
    cout<<"Bipartite Check on Adjencency List:";
    color = vector<int>(ADJ_MAT.size(),-1);
    is_bipartite = true;
    for(int i = 0; i < ADJ_LST.size();i++){
        if(color[i] == -1){
            is_bipartite = bfs_ADJ_LST(i,ADJ_LST, color);
            if(is_bipartite == false)
                break;
        }
    }
    (is_bipartite)?cout<<" True.\n":cout<<" False.\n";

}