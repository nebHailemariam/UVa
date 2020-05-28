#include <bits/stdc++.h>
using namespace std;


int UNVISITED = -1;
vector<vector<int>> ADJ_LST;
int root;
int root_children;
int dfs_count;
vector<int> num; 
vector<int> low;// stores the lowest dfsnum reachable from the currne DFS spanning subtree of u.
vector<int> par;
vector <bool> articulation_point;
void articulationPoint(int u){
    num[u] = dfs_count;
    low[u] = dfs_count;
    dfs_count++;

    for(int i = 0; i < ADJ_LST[u].size();i++){
        int v = ADJ_LST[u][i];

        if(num[v] == UNVISITED){
            par[v] = u;
            if(u == root)
                root_children++;

            articulationPoint(v);

            if(low[v] >= num[u])
                articulation_point[u] = true;
            if(low[v] > num[u])
                cout<<" Edge ("<<u<<","<<v<<") is a bridge.\n";

            low[u] = min(low[u],low[v]);
        }else if(v != par[u])
            low[u] = min(low[u], num[v]);
    }

}


int main(){
    ADJ_LST = {
        {1},
        {0, 2, 3, 4},
        {1},
        {1},
        {1,5},
        {1,4}
    };
    num = vector<int>(ADJ_LST.size(), UNVISITED);
    low = vector<int>(ADJ_LST.size(), 0);
    par = vector<int>(ADJ_LST.size(),0);
    articulation_point = vector<bool>(ADJ_LST.size(),false);
    cout<<"Bridges:\n";
    for(int i = 0;i < ADJ_LST.size();i++){
        if(num[i] == UNVISITED){
            root = i;
            root_children = 0;
            articulationPoint(i);
            articulation_point[i] = (root_children > 1)?true:false;
        }
    }
    cout<<"Articulation points:\n";
    for(int i=0;i< ADJ_LST.size();i++){
        if(articulation_point[i])
            cout<<" Vertex "<<i<<"\n";
    }

}