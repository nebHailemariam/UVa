#include <bits/stdc++.h>
using namespace std;

//Adj_MAT implementation
//O(V^2)
bool dfs_ADJ_MAT(int start, vector<vector<int>> &ADJ_MAT, vector<int> &color, int c){
    if(color[start] != -1 && color[start] != c)
        return false;
    color[start] = c;
    bool ans = true;
    for(int i = 0; i < ADJ_MAT.size();i++){
        if(ADJ_MAT[start][i] != 0 && color[i] == -1)
            ans = dfs_ADJ_MAT(i,ADJ_MAT,color, 1-c);
        else if(ADJ_MAT[start][i] != 0 && color[i] == color[start])
            return false;
        
        if(!ans)
            return false;
    }
    return true;
}

bool dfs_ADJ_LST(int start, vector<vector<int>> &ADJ_LST, vector<int> &color, int c){
    if(color[start] != -1 && color[start] != c)
        return false;
    color[start] = c;
    bool ans = true;
    for(int i = 0; i < ADJ_LST[start].size();i++){
        if(color[ADJ_LST[start][i]] == -1)
            ans = dfs_ADJ_LST(ADJ_LST[start][i],ADJ_LST, color,1-c);
        else if(color[ADJ_LST[start][i]] == color[start])
            return false;
        if(!ans)
            return false;
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
            is_bipartite = dfs_ADJ_MAT(i,ADJ_MAT, color,0);
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
        is_bipartite = dfs_ADJ_LST(i,ADJ_LST, color,0);
        if(is_bipartite == false)
            break;
        }
    }
    (is_bipartite)?cout<<" True.\n":cout<<" False.\n";

}