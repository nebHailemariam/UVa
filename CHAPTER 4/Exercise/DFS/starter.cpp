#include <bits/stdc++.h>
using namespace std;

//Adj_MAT implementation
//O(V^2)
void dfs_ADJ_MAT(int start, vector<vector<int>> &ADJ_MAT, vector<int> &V,string path){
    V[start] = 1;
    path += to_string(start)+" ";
    cout<<path<<"\n";
    for(int i = 0; i < V.size();i++){
        if(ADJ_MAT[start][i] != 0 && V[i] == -1){
            dfs_ADJ_MAT(i,ADJ_MAT, V, path);
        }
    }
}

void dfs_ADJ_LST(int start, vector<vector<int>> &ADJ_LST, vector<int> &V, string path){
    V[start] = 1;
    path += to_string(start)+" ";
    cout<<path<<"\n";
    for(int i = 0; i < ADJ_LST[start].size();i++){
        if(V[ADJ_LST[start][i]] == -1)
            dfs_ADJ_LST(ADJ_LST[start][i],ADJ_LST, V, path);
    }
}


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> ADJ_MAT{
        {0,1,0,1},
        {1,0,0,0},
        {0,0,0,0},
        {0,0,1,0}
    };
    vector<int> visted = vector<int>(ADJ_MAT.size(),-1);
    vector<vector<int>> ADJ_LST{
        {1,3},
        {0},
        {},
        {2}
    };
    cout<<"Adjecency Matrixs:\n";
    dfs_ADJ_MAT(0,ADJ_MAT, visted,"");
    cout<<"\n";
    visted = vector<int>(ADJ_LST.size(),-1);
    cout<<"Adjencency List:\n";
    dfs_ADJ_LST(0,ADJ_LST, visted,"");

}