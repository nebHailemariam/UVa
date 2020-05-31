#include <bits/stdc++.h>
using namespace std;

int UNVISITED = -1;
vector<int> visited;
vector<int> dfs_num;
vector<int> dfs_low;
int dfs_count;
vector<int> S;//stack to store the connected components
int numSCC;


void tarjanSCC(int u, vector<vector<int>> &ADJ_LST){
    dfs_num[u] = dfs_count;
    dfs_low[u] = dfs_count;
    dfs_count++;
    visited[u] = 1;
    S.push_back(u);
    
    for(int i = 0; i < ADJ_LST[u].size();i++){
        int v = ADJ_LST[u][i];
        if(visited[v] == UNVISITED)
            tarjanSCC(v,ADJ_LST);
        if(visited[v])// Condition for descendants of SCC
            dfs_low[u] = min(dfs_low[u],dfs_low[v]);
    }

    if(dfs_num[u] == dfs_low[u]){// Condition for root vertex
        cout<<"SCC "<<numSCC<<": ";
        numSCC++;
        while(true){
            int v = S.back();
            S.pop_back();
            visited[v] = 0;
            cout<<v<<" ";
            if(v == u)
                break;

        }cout<<"\n";
    }
}


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> ADJ_LST{
        {1,3},
        {0},
        {},
        {2},
        {3}
    };
    visited = vector<int>(ADJ_LST.size(), UNVISITED);
    dfs_num = vector<int>(ADJ_LST.size(), 0);
    dfs_low = vector<int>(ADJ_LST.size(), 0);
    dfs_count = 0;
    numSCC = 0;
    for(int i = 0; i < visited.size();i++)
        if(visited[i] == UNVISITED)
            tarjanSCC(i,ADJ_LST);
}