#include <bits/stdc++.h>
using namespace std;

//Adj_MAT implementation
//O(V^2)

int Unvisited = -1;
int Visited = 1;
int Explored = 2;

void dfs_ADJ_LST(int u, vector<vector<int>> &ADJ_LST, vector<int> &visited, vector<int> &par){
    visited[u] = Explored;

    for(int i = 0; i < ADJ_LST[u].size();i++){
        int v = ADJ_LST[u][i];

        if(visited[v] == Unvisited){
            par[v] = u;
            dfs_ADJ_LST(v,ADJ_LST, visited, par);
        }else if(visited[v] == Explored){
            if(par[u] == v)
                cout<<"Two ways ("<<v<<", "<<u<<")"<<" - "<<"("<<u<<", "<<v<<")\n";
            else
                cout<<"Two ways ("<<v<<", "<<u<<") (Cycle)\n";
                
        }else if(visited[v] == Visited){
            cout<<"Forward/cross Edge ("<<u<<","<<v<<")\n";
        }
    }
    visited[u] = Visited;
}


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> ADJ_LST{
        {1},
        {0,2},
        {1,3},
        {1,2,4},
        {3},
        {},
        {7,8},
        {6},
        {6},
    };
    vector<int> visited = vector<int>(ADJ_LST.size(),-1);
    vector<int> par = vector<int>(ADJ_LST.size(),-1);
    int comp_num = 1;
    for(int i = 0; i < ADJ_LST.size();i++){
        
        if(visited[i] == Unvisited){
            cout<<"Component "<<comp_num++<<":\n";
            dfs_ADJ_LST(i, ADJ_LST, visited, par);
        }
    }
    

}